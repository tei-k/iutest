#!/usr/bin/env python
#
# iutwilio.py
#

import os
import sys
import argparse
import ConfigParser
import twilio
import xml.etree.ElementTree as ET

from argparse import ArgumentParser
from twilio.rest import TwilioRestClient

account_sid= ''
auth_token = ''
my_number  = ''
sms_number  = ''


#
# command line option
def parse_command_line():
	parser = ArgumentParser()
	parser.add_argument(
		'-v'
		, '--version'
		, action='version'
		, version=u'%(prog)s version 0.3'
	)
	parser.add_argument(
		'--ini'
		, help = 'ini file path.'
		, default = 'config.ini'
	)
	parser.add_argument(
		'--call'
		, help = 'call to number.'
	)
	parser.add_argument(
		'--sms'
		, help = 'send message number.'
	)
	parser.add_argument(
		'--account_sid'
		, help = 'account sid.'
	)
	parser.add_argument(
		'--auth_token'
		, help = 'auth token.'
	)
	parser.add_argument(
		'--number'
		, help = 'twilio phone number.'
	)
	parser.add_argument(
		'--dump'
		, action = 'store_true'
		, help = 'dump setting.'
	)
	parser.add_argument(
		'--dryrun'
		, action = 'store_true'
		, help = 'dryrun.'
	)
	parser.add_argument(
		'--url'
		, help = 'TwiML url.'
		, default = 'http://twimlbin.com/2e6ad348'
	)
	parser.add_argument(
		'xml'
		, metavar='XML'
		, help = 'test result xml file'
		, nargs='?'
	)
	del sys.argv[0]
	options = parser.parse_args(sys.argv)
	
	if not options.dump:
		if not options.xml:
			if not options.call:
				parser.print_help()
	
	return options

#
# setup
def setup(options):
	global account_sid
	global auth_token
	global my_number
	global sms_number
	if options.account_sid:
		account_sid = options.account_sid
	if options.auth_token:
		auth_token = options.auth_token
	if options.number:
		my_number = options.number
		sms_number = options.number

#
# parse ini
def parse_ini(path):
	global account_sid
	global auth_token
	global my_number
	global sms_number
	if account_sid and auth_token and my_number:
		return
	ini = ConfigParser.SafeConfigParser()
	if not os.path.exists(path):
		sys.stderr.write('%s not found...' % path)
		sys.exit(2)
	ini.read(path)
	
	try:
		account_sid = ini.get('Twilio', 'account_sid')
		auth_token = ini.get('Twilio', 'auth_token')
		my_number = ini.get('Twilio', 'my_number')
		sms_number = ini.get('Twilio', 'sms_number')
	except:
		pass
		
#	for section in ini.sections():
#		print '[%s]' % (section)
#		for key in ini.options(section):
#			print '%s.%s =%s' % (section, key, ini.get(section, key))

#
# parse xml
def parse_xml(path):
	tree = ET.parse(path)
	root = tree.getroot()
	testsuites = root.find('[@failures]')
	return testsuites.attrib['failures']

#
# make twilio client
def make_twilio():
	client = TwilioRestClient(account_sid, auth_token)
	return client

#
# call twilio
def call(client, options):
	if options.dryrun:
		print 'twilio call to ' + options.call
		print body
	else:
		call = client.calls.create(url=options.url,
			to=options.call,
			from_=my_number)
		print call.sid


#
# make_message
def make_message(options):
	body = ""
	filepath = options.xml
	if filepath and os.path.exists(filepath):
		tree = ET.parse(filepath)
		root = tree.getroot()
		tests = int(root.get('tests'))
		testcases = len(root.findall('testsuite'))
		failures = int(root.get('failures'))
		disabled = int(root.get('disabled'))
		skipped = int(root.get('skip'))
		passed = tests - failures - skipped
		time = root.get('time')
		timestamp = root.get('timestamp')

		if timestamp:
			body += "%s\n" % (timestamp)
		first_failure = None
		
		body += "%d tests from %s testcase ran. (%sms total)\n" % (tests, testcases, time)
		if passed:
			body += "PASSED  : %d\n" % (passed)
		if disabled:
			body += "DISABLED: %d\n" % (disabled)
		if skipped:
			body += "SKIPPED : %d\n" % (skipped)
		if failures:
			body += "FAILED  : %d\n" % (failures)
		failure_testsuites = root.findall('testsuite')
		for suite in failure_testsuites:
			if int(suite.get('failures')):
				for test in suite:
					failure_node = test.find('.//failure')
					if failure_node != None:
						if not first_failure:
							first_failure = failure_node
						name = "%s.%s\n" % ( suite.get('name'), test.get('name') )
						if len(body) + len(name) < 155:
							body += name;
						else:
							body += "..."
							return body
		if first_failure != None:
			for s in first_failure.text.split('\n'):
				if len(body) + len(s) < 155:
					body += "%s\n" % s
				else:
					body += "..."
					return body
	return body


#
# message
def message(client, options):
	m = make_message(options)
	if options.dryrun:
		print 'twilio call to ' + options.sms
		print m
	else:
		call = client.messages.create(body=m,
			to=options.sms,
			from_=sms_number)
		print call.sid

#
# run
def run(options):
	filepath = options.xml
	if filepath:
		if not os.path.exists(filepath):
			sys.exit(1)
		else:
			if parse_xml(filepath) > 0:
				if options.sms:
					message(make_twilio(), options)
				elif options.call:
					call(make_twilio(), options)
				else:
					print 'was failed ' + filepath
	else:
		if options.call:
			call(make_twilio(), options)

	sys.exit(0)

#
# dump
def dump(options):
	print 'account_sid: %s' % (account_sid)
	print 'auth_token : %s' % (auth_token)
	print 'my_number  : %s' % (my_number)
	if options.call:
		print 'call       : %s' % (options.call)
	if options.sms:
		print 'sms        : %s' % (options.sms)

#
#
def main():
	options = parse_command_line()
	setup(options)
	parse_ini(options.ini)
	if options.dump:
		dump(options)
	else:
		run(options)

if __name__ == '__main__':
	main()

﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_output_junit_xml_tests.cpp
 * @brief		output junit xml test
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"

#if !defined(IUTEST_USE_GTEST) && IUTEST_HAS_STRINGSTREAM && IUTEST_HAS_ASSERTION_RETURN
#  define OUTPUT_JUNIT_XML_TEST	1
#else
#  define OUTPUT_JUNIT_XML_TEST	0
#endif

#if OUTPUT_JUNIT_XML_TEST

class FileIO : public ::iutest::StringStreamFile
{
public:
	static ::std::string s_io;

	virtual void Close()
	{
		s_io = ss.str();
	}
};

::std::string FileIO::s_io;

IUTEST_FILESYSTEM_INSTANTIATE(FileIO);

#endif

IUTEST(Test, Fail)
{
	IUTEST_ASSERT_EQ(2, 3);
}

IUTEST(Fail, Test)
{
	IUTEST_ASSERT_EQ(2, 3);
}

IUTEST(Foo, Bar)
{
	IUTEST_ASSERT_EQ(3, 3);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
#if OUTPUT_JUNIT_XML_TEST
	IUTEST_INIT(&argc, argv);

	::iutest::IUTEST_FLAG(output) = "junit:test.xml";

	{
		::iutest::IUTEST_FLAG(filter) = "-*Fail*";
		const int ret = IUTEST_RUN_ALL_TESTS();
		
		if( ret != 0 ) return 1;
		IUTEST_ASSERT_EQ( "test.xml"
			, (reinterpret_cast< ::iutest::DefaultXmlGeneratorListener*>(::iutest::TestEnv::event_listeners().default_xml_generator())->GetFilePath()) )
				 << ::iutest::AssertionReturn<int>(1);
		IUTEST_ASSERT_EQ(::std::string::npos, FileIO::s_io.find("Fail")) << FileIO::s_io << ::iutest::AssertionReturn<int>(1);
		IUTEST_ASSERT_NE(::std::string::npos, FileIO::s_io.find("Foo" )) << FileIO::s_io << ::iutest::AssertionReturn<int>(1);
		
		FileIO::s_io.clear();
	}

	::iutest::IUTEST_FLAG(output) = "junit";
	{
		::iutest::IUTEST_FLAG(filter) = "*Fail*";
		const int ret = IUTEST_RUN_ALL_TESTS();
		
		if( ret == 0 ) return 1;
		IUTEST_ASSERT_EQ( ::iutest::detail::kStrings::DefaultXmlReportFileName
			, (reinterpret_cast< ::iutest::DefaultXmlGeneratorListener*>(::iutest::TestEnv::event_listeners().default_xml_generator())->GetFilePath()) )
				 << ::iutest::AssertionReturn<int>(1);
		IUTEST_ASSERT_NE(::std::string::npos, FileIO::s_io.find("Fail")) << FileIO::s_io << ::iutest::AssertionReturn<int>(1);
		IUTEST_ASSERT_EQ(::std::string::npos, FileIO::s_io.find("Foo" )) << FileIO::s_io << ::iutest::AssertionReturn<int>(1);

		FileIO::s_io.clear();
	}
	printf("*** Successful ***\n");
#else
	(void)argc;
	(void)argv;
	printf("*** OUTPUT_JUNIT_XML_TEST=0 ***\n");
#endif
	return 0;
}

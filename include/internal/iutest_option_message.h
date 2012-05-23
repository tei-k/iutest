//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_option_message.h
 * @brief		iris unit test コマンドラインメッセージ ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2011-2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_option_message_H_00EB9B17_0615_4678_9AD0_1F5B295B404F_
#define INCG_IRIS_iutest_option_message_H_00EB9B17_0615_4678_9AD0_1F5B295B404F_

//======================================================================
// include
#include "iutest_console.hpp"

namespace iutest {
namespace detail
{

//======================================================================
// class
class iuOptionMessage
{
public:
	/**
	 * @brief	ヘルプの出力
	*/
	static void	ShowHelp(void)
	{
		const char readme[] = 
			"--------------------------------------------------\n"
			"Name\n"
			"    iutest - iris unit test framework\n"
			"--------------------------------------------------\n"
			"Command Line Options\n"
			"\n"
			"    --help, -h                        : generate help message.\n"
			"    --iutest_output=xml[:path]        : path of xml report.\n"
			"    --iutest_list_tests               : list up tests.\n"
			"    --iutest_color=<yes|no|auto|ansi> : console color enable.\n"
			"    --iutest_filter=<filter>          : Select the test run.\n"
			"    --iutest_shuffle                  : do shuffle test.\n"
			"    --iutest_random_seed=<seed>       : set random seed.\n"
			"    --iutest_also_run_disabled_tests  : run disabled tests.\n"
			"    --iutest_break_on_failure[=0|1]   : When that failed to break.\n"
			"    --iutest_throw_on_failure[=0|1]   : When that failed to throw.\n"
			"    --iutest_catch_exceptions=<0|1>   : catch exceptions enable.\n"
			"    --iutest_print_time=<0|1>         : Setting the display of elapsed time.\n"
			"    --iutest_repeat=<count>           : Set the number of repetitions of the test.\n"
			"    --version, -v                     : show iutest version.\n"
			"\n"
			"--------------------------------------------------\n"
			"License\n"
			"\n"
			"    Copyright (c) 2011-2012, Takazumi-Shirayanagi,\n"
			"    All rights reserved.\n"
			"\n"
			"    The new(modified) BSD License is applied to this software, see LICENSE\n"
			"\n"
			;
		detail::iuConsole::color_output(detail::iuConsole::cyan, readme);
	}
	/**
	 * @brief	バージョン出力
	*/
	static void	ShowVersion(void)
	{
		detail::iuConsole::output("iutest version %x.%x.%x.%x\n"
			, IUTEST_MAJORVER, IUTEST_MINORVER, IUTEST_BUILD, IUTEST_REVISION);
	}
};

}	// end of namespace detail
}	// end of namespace iutest

#endif

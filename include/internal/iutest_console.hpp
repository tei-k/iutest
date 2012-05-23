//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_console.hpp
 * @brief		iris unit test console ファイル
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
#ifndef INCG_IRIS_iutest_console_HPP_DCAC5025_B7BB_424e_A849_9E6FE0A3B460_
#define INCG_IRIS_iutest_console_HPP_DCAC5025_B7BB_424e_A849_9E6FE0A3B460_

//======================================================================
// include
#include <stdio.h>
#include <stdarg.h>

namespace iutest {
namespace detail
{

//======================================================================
// define
#ifndef IUTEST_VPRINTF
#  define IUTEST_VPRINTF(f, a)	vprintf(f, a)
#endif
#ifndef IUTEST_PRINTF
#  define IUTEST_PRINTF			printf
#endif

#ifndef IUTEST_HAS_COLORCONSOLE
#  if defined(IUTEST_OS_WINDOWS_MOBILE) || defined(IUTEST_OS_NACL)
#    define IUTEST_HAS_COLORCONSOLE	0	//!< 色つきターミナルが使用可能かどうか
#  else
#    define IUTEST_HAS_COLORCONSOLE	1	//!< 色つきターミナルが使用可能かどうか
#  endif
#endif

//======================================================================
// class
/**
 * @internal
 * @brief	コンソールクラス
*/
class iuConsole
{
public:
	//! コンソール文字色
	enum Color
	{
		black,
		red,
		green,
		yellow,
		blue,
		magenta,
		cyan,
		white
	};
public:
	/**
	 * @brief	標準出力
	*/
	static void	output(const char *fmt, ...)
	{
		va_list va;
		va_start(va, fmt);
		IUTEST_VPRINTF(fmt, va);
		va_end(va);
	}
	/**
	 * @brief	色指定で標準出力
	 * @param [in]	color	= 文字色
	*/
	static void	color_output(Color color, const char *fmt, ...)
	{
		va_list va;
		va_start(va, fmt);

		if( IsShouldUseColor(true) )
		{
			color_output_impl(color, fmt, va);
		}
		else
		{
			IUTEST_VPRINTF(fmt, va);
		}

		va_end(va);
	}

private:
	static void color_output_impl(Color color, const char* fmt, va_list va)
	{
#if defined(IUTEST_OS_WINDOWS) && !defined(IUTEST_OS_WINDOWS_MOBILE)
		if( !IsColorModeAnsi() )
		{
			const WORD attr[] = {
				0,
				FOREGROUND_RED,
				FOREGROUND_GREEN,
				FOREGROUND_GREEN | FOREGROUND_RED,
				FOREGROUND_BLUE,
				FOREGROUND_RED | FOREGROUND_BLUE,
				FOREGROUND_GREEN | FOREGROUND_BLUE,
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
			};
			const HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			::GetConsoleScreenBufferInfo(stdout_handle, &csbi);
			const WORD wAttributes = csbi.wAttributes;

			fflush(stdout);
			::SetConsoleTextAttribute(stdout_handle, attr[color] | FOREGROUND_INTENSITY);

			IUTEST_VPRINTF(fmt, va);

			fflush(stdout);
			::SetConsoleTextAttribute(stdout_handle, wAttributes);
		}
		else
#endif
		{
			IUTEST_PRINTF("\033[1;3%cm", '0' + color);
			IUTEST_VPRINTF(fmt, va);
			IUTEST_PRINTF("\033[m");
		}
	}

private:
	static bool	IsShouldUseColor(bool use_color)
	{
		if( IsColorModeOn() )
		{
			return true;
		}
		else if( IsColorModeOff() )
		{
			return false;
		}

#if !IUTEST_HAS_COLORCONSOLE
		(void)(use_color);
		return false;
#else
#if defined(IUTEST_OS_WINDOWS)
		return use_color;
#else
		const char* env = internal::posix::GetEnv("TERM");
		bool term_conf = (env != NULL) && (
			   IsStringEqual(env, "xterm")
			|| IsStringEqual(env, "xterm-color")
			|| IsStringEqual(env, "xterm-256color")
			|| IsStringEqual(env, "screen")
			|| IsStringEqual(env, "linux")
			|| IsStringEqual(env, "cygwin")
			);
		return use_color && term_conf;
#endif

#endif
	}
private:
	static inline bool IsStringEqual(const char* str1, const char* str2) { return strcmp(str1, str2) == 0; }

	static bool	IsColorModeOff(void)
	{
#if	defined(INCG_IRIS_iutest_HPP_) && !defined(IUTEST_USE_GTEST)
		return TestFlag::IsEnableFlag(TestFlag::CONSOLE_COLOR_OFF);
#else
		return IUTEST_FLAG(color) == "no";
#endif
	}
	static bool	IsColorModeOn(void)
	{
#if	defined(INCG_IRIS_iutest_HPP_) && !defined(IUTEST_USE_GTEST)
		return TestFlag::IsEnableFlag(TestFlag::CONSOLE_COLOR_ON);
#else
		return IUTEST_FLAG(color) == "yes";
#endif
	}
	static bool IsColorModeAnsi(void)
	{
#if	defined(INCG_IRIS_iutest_HPP_) && !defined(IUTEST_USE_GTEST)
		return TestFlag::IsEnableFlag(TestFlag::CONSOLE_COLOR_ANSI);
#else
		return false;
#endif
	}
};


}	// end of namespace detail
}	// end of namespace iutest

#endif

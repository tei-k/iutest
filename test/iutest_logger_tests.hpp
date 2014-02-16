﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_logger_tests.cpp
 * @brief		logger テスト
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
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

#if !defined(IUTEST_USE_GTEST)

class TestLogger : public ::iutest::detail::iuLogger
{
	::std::string m_log;
public:
	virtual void voutput(const char* fmt, va_list va)
	{
		char buf[256];
		vsprintf(buf, fmt, va);
		m_log += buf;
		::iutest::detail::iuConsole::voutput(fmt, va);
	}
	void clear(void) { m_log.clear(); }
public:
	const char* c_str(void) const { return m_log.c_str(); }
};

#endif

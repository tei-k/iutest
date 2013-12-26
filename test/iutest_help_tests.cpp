//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_help_tests.cpp
 * @brief		help �Ή��e�X�g
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"

IUTEST(Foo, NotRun)
{
	IUTEST_ASSERT_EQ(0, 1);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	(void)argc;
	int targc = 2;
#ifdef UNICODE
	const wchar_t* targv[] = {
		argv[0]
		, L"--help"
	};
#else
	const char* targv[] = {
		argv[0]
		, "--help"
	};
#endif
	IUTEST_INIT(&targc, targv);
	return IUTEST_RUN_ALL_TESTS();
}

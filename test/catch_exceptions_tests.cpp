﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        catch_exceptions_tests.cpp
 * @brief       catch_exceptions 対応テスト
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "iutest.hpp"


#if IUTEST_HAS_EXCEPTIONS

IUTEST(Foo, Bar)
{
    throw "error";
}

void TerminateHandler(void)
{
    printf("called as expected.\n");
    printf("*** Successful ***\n");
    exit(0);
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
    ::iutest::IUTEST_FLAG(catch_exceptions) = false;

#if IUTEST_HAS_EXCEPTIONS
    ::std::set_terminate(&TerminateHandler);
#endif

    IUTEST_INIT(&argc, argv);
#if defined(OUTPUTXML)
    // 失敗テストを含むので xml 出力しない
    ::iutest::IUTEST_FLAG(output) = NULL;
#endif
    return IUTEST_RUN_ALL_TESTS();
}

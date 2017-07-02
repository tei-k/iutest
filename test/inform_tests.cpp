﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        inform_tests.cpp
 * @brief       iutest inform flavor test
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2017, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/gtest/iutest_spi_switch.hpp"

IUTEST(InformTest, A)
{
    IUTEST_INFORM_TRUE(false);
}
#ifdef UNICODE
int wmain(int argc, wchar_t** argv)
#else
int main(int argc, char** argv)
#endif
{
    IUTEST_INIT(&argc, argv);
#if defined(OUTPUTXML)
    // 失敗テストを含むので xml 出力しない
    ::iutest::IUTEST_FLAG(output) = NULL;
#endif
    const int ret = IUTEST_RUN_ALL_TESTS();
#if !defined(IUTEST_USE_GTEST)
    if( ret != 0 ) return 1;
    IUTEST_ASSERT_EXIT( ::iutest::UnitTest::GetInstance()->successful_test_case_count() == 1 );
    IUTEST_ASSERT_EXIT( ::iutest::UnitTest::GetInstance()->failed_test_count() == 0 );
#endif
    printf("*** Successful ***\n");
    return 0;
}


﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        spi_tests.cpp
 * @brief       iutest spi test
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2019, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/gtest/iutest_spi_switch.hpp"
#include "pred_tests.hpp"

namespace spi_test
{

class SPITest : public ::iutest::Test
{
public:
#if IUTEST_HAS_SPI_LAMBDA_SUPPORT
    const char* null_str;
    const int a, b;
    const float fa;
    const double da;
    int  aa[5];
    int  ab[6];
    char ac[5];
    const ::std::string sa;
    const ::std::string sb;
    const ::std::string sa2;

    SPITest()
        : null_str(NULL)
        , a(0), b(0)
        , fa(0.0f)
        , da(0.0)
        , sa("a")
        , sb("b")
    {
        const char ac_[5] = { 0, 0, 2, 3, 5 };
        for( int i=0; i < 5; ++i )
        {
            aa[i] = ab[i] = i;
            ac[i] = ac_[i];
        }
        ab[5] = 5;
    }
#endif

public:
    void FatalFailure_Sub(int& count);
    void FatalFailure2_Sub(int& count);
};

#if !IUTEST_HAS_SPI_LAMBDA_SUPPORT
const char* null_str = NULL;
const int a=0, b=0;
const int  aa[] = { 0, 1, 2, 3, 4 };
const int  ab[] = { 0, 1, 2, 3, 4, 5 };
const char ac[] = { 0, 0, 2, 3, 5 };
const ::std::string sa="a";
const ::std::string sb="b";
const float fa = static_cast<float>(a);
const double da = static_cast<double>(a);
#endif

void SPITest::FatalFailure_Sub(int& count)
{
    #define FLAVOR(n) IUTEST_ASSERT##n
    #define FAILURE_MACRO IUTEST_ASSERT_FATAL_FAILURE

#include "spi_tests_decl.cpp"

    #undef FLAVOR
    #undef FAILURE_MACRO

    count++;
}

IUTEST_F(SPITest, FatalFailure)
{
    int count=0;
#if IUTEST_HAS_EXCEPTIONS
    try {
        FatalFailure_Sub(count);
    } catch(...) {
    }
#else
    FatalFailure_Sub(count);
#endif
    IUTEST_ASSERT_EQ(1, count);
}

void SPITest::FatalFailure2_Sub(int& count)
{
    #define FLAVOR(n) IUTEST_ASSERT##n
    #define FAILURE_MACRO IUTEST_EXPECT_FATAL_FAILURE

#include "spi_tests_decl.cpp"

    #undef FLAVOR
    #undef FAILURE_MACRO

    count++;
}

IUTEST_F(SPITest, FatalFailure2)
{
    int count=0;
#if IUTEST_HAS_EXCEPTIONS
    try {
        FatalFailure2_Sub(count);
    } catch(...) {
    }
#else
    FatalFailure2_Sub(count);
#endif
    IUTEST_ASSERT_EQ(1, count);
}

IUTEST_F(SPITest, NonFatalFailure)
{
    #define FLAVOR(n) IUTEST_EXPECT##n
    #define FAILURE_MACRO IUTEST_ASSERT_NONFATAL_FAILURE

#include "spi_tests_decl.cpp"

    #undef FLAVOR
    #undef FAILURE_MACRO
}

IUTEST_F(SPITest, NonFatalFailure2)
{
    #define FLAVOR(n) IUTEST_EXPECT##n
    #define FAILURE_MACRO IUTEST_EXPECT_NONFATAL_FAILURE

#include "spi_tests_decl.cpp"

    #undef FLAVOR
    #undef FAILURE_MACRO
}

}   // end of namespace spi_test

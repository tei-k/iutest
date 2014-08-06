﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_tr1_failurecount_assertion_tests.cpp
 * @brief		failurecount assertion test
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

#if !defined(IUTEST_USE_GTEST)

#include "../include/tr1/iutest_failurecount_assertion.hpp"

static int f() { return 42; }

IUTEST(FailureCountTest, Test)
{
	IUTEST_ASSERT_FAILURECOUNT_LT(IUTEST_EXPECT_EQ(f(), 42); IUTEST_EXPECT_EQ(f(), 0), 2);
	IUTEST_EXPECT_FAILURECOUNT_LT(IUTEST_EXPECT_EQ(f(), 42); IUTEST_EXPECT_EQ(f(), 0), 2);
	IUTEST_INFORM_FAILURECOUNT_LT(IUTEST_EXPECT_EQ(f(), 42); IUTEST_EXPECT_EQ(f(), 0), 2);
	IUTEST_ASSUME_FAILURECOUNT_LT(IUTEST_EXPECT_EQ(f(), 42); IUTEST_EXPECT_EQ(f(), 0), 2);
}


#endif

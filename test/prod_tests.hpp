﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        prod_tests.hpp
 * @brief       product code access test
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IUTEST_PROD_TESTS_HPP_
#define INCG_IUTEST_PROD_TESTS_HPP_

//======================================================================
// include
#include "iutest.hpp"

namespace prod_test
{

#if IUTEST_HAS_TYPED_TEST_P
IUTEST_FRIEND_TYPED_TEST_P_DECLARATION(ProdTypeParamTest, Friend)
#endif

class ProdClass
{
    IUTEST_FRIEND_TEST(ProdTest, Friend);
    IUTEST_FRIEND_TEST(ProdFixtureTest, Friend);
#if IUTEST_HAS_PARAM_TEST
    IUTEST_FRIEND_TEST(ProdParamTest, Friend);
#endif
#if IUTEST_HAS_TYPED_TEST
    IUTEST_FRIEND_TYPED_TEST(ProdTypedTest, Friend);
#endif
#if IUTEST_HAS_TYPED_TEST_P
    IUTEST_FRIEND_TYPED_TEST_P(ProdTypeParamTest, Friend);
#endif

public:
    ProdClass(void) : m_dummy(0), m_x(0), m_z(0), m_a(0), m_c(42) {}
    ProdClass(const ProdClass& rhs) : m_dummy(rhs.m_dummy), m_x(rhs.m_x), m_z(rhs.m_z), m_a(rhs.m_a), m_c(42) {}

    int GetA(void) const { return m_a; }
    int GetX(void) const { return m_x; }
    int GetZ(void) const { return m_z; }
private:
    int m_dummy;
    int m_x;
    int m_z;
    int m_a;
    const int m_c;
    void SetX(int x) { m_x = x; }
    int ConstGetX(void) const { return m_x; }

public:
    static int GetY(void)   { return m_y; }
private:
    static int m_y;
    static void SetY(int y) { m_y = y; }
private:
    ProdClass& operator = (const ProdClass&);
};

class ProdClass2
{
public:
    int GetX(void) { return m_x; }
private:
    int m_x;
};

#if IUTEST_HAS_PEEP

IUTEST_MAKE_PEEP(int ProdClass::*, ProdClass, m_a);

#endif

}   // end of namespace prod_test

#endif

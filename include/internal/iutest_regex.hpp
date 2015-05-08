﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_regex.hpp
 * @brief		regex
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2011-2015, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_REGEX_HPP_1575CB44_189A_4248_B305_DB4882E3BFC2_
#define INCG_IRIS_IUTEST_REGEX_HPP_1575CB44_189A_4248_B305_DB4882E3BFC2_

//======================================================================
// include
#include "iutest_stdlib.hpp"
#if IUTEST_HAS_CXX_HDR_REGEX
#  include <regex>
#endif

namespace iutest {
namespace detail
{

/**
 * @brief	filter regex クラス
*/
class iuFilterRegex
{
	static bool match_impl(const char* begin, const char* end, const char* src);
	static bool match_impl_group(const char* begin, const char* end, const char* src);
public:
	static bool match(const char* regex, const char* src);
};

#if IUTEST_HAS_CXX_HDR_REGEX

/**
* @brief	regex クラス
*/
class iuRegex
{
public:
	iuRegex(const char* pattern) { Init(pattern); }
	iuRegex(const ::std::string& pattern) { Init(pattern.c_str()); }
public:
	bool FullMatch(const char* str) const;
	bool PartialMatch(const char* str) const;

	const char* pattern() const { m_pattern.c_str(); }

private:
	void Init(const char* pattern);

private:
	::std::regex m_re;
	::std::string m_pattern;

	IUTEST_PP_DISALLOW_ASSIGN(iuRegex);
};

#endif

}	// end of namespace detail
}	// end of namespace iutest

#if !IUTEST_HAS_LIB
#  include "../impl/iutest_regex.ipp"
#endif

#endif // INCG_IRIS_IUTEST_REGEX_HPP_1575CB44_189A_4248_B305_DB4882E3BFC2_

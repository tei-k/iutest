﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_stdlib.hpp
 * @brief		iris unit test stdlib
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_STDLIB_HPP_54D4BEEE_7B6B_4AF4_B1F6_138560480D55_
#define INCG_IRIS_IUTEST_STDLIB_HPP_54D4BEEE_7B6B_4AF4_B1F6_138560480D55_

//======================================================================
// include
#if defined(IUTEST_USE_GTEST) && defined(__STRICT_ANSI__)
#  undef __STRICT_ANSI__
#  include <string.h>
#  include <stdlib.h>
#  include <cstdio>
#  define __STRICT_ANSI__
#endif
#include <cstdlib>
#include <cstddef>

//======================================================================
// define

#if   defined(__GLIBCPP__) || defined(__GLIBCXX__)

// libstdc++
#if   defined(__clang__)
#  if __has_include(<experimental/any>)
#    define IUTEST_LIBSTDCXX_VERSION	50100
#  elif __has_include(<shared_mutex>)
#    define IUTEST_LIBSTDCXX_VERSION	40900
#  elif __has_include(<ext/cmath>)
#    define IUTEST_LIBSTDCXX_VERSION	40800
#  elif   __has_include(<chrono>)
#    define IUTEST_LIBSTDCXX_VERSION	40700
#  elif __has_include(<typeindex>)
#    define IUTEST_LIBSTDCXX_VERSION	40400
#  elif __has_include(<future>)
#    define IUTEST_LIBSTDCXX_VERSION	40400
#  elif __has_include(<ratio>)
#    define IUTEST_LIBSTDCXX_VERSION	40400
#  elif __has_include(<array>)
#    define IUTEST_LIBSTDCXX_VERSION	40300
#  endif
#elif defined(__GNUC__)
#  define IUTEST_LIBSTDCXX_VERSION		(__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__)
#endif

#if IUTEST_HAS_CXX11
#  if IUTEST_LIBSTDCXX_VERSION >= 50100
#    define IUTEST_HAS_CXX_HDR_CODECVT	1
#  endif
#  if IUTEST_LIBSTDCXX_VERSION >= 40900
#    define IUTEST_HAS_CXX_HDR_REGEX	1
#  endif
#  if IUTEST_LIBSTDCXX_VERSION >= 40700
#    define IUTEST_HAS_STD_EMPLACE		1
#    define IUTEST_HAS_CXX_HDR_CHRONO	1
#  endif
#  if IUTEST_LIBSTDCXX_VERSION >= 40600
#    define IUTEST_HAS_STD_BEGIN_END	1
#  endif
#  if IUTEST_LIBSTDCXX_VERSION >= 40500
#    define IUTEST_HAS_STD_DECLVAL		1
#    define IUTEST_HAS_CXX_HDR_RANDOM	1
#  endif
#endif

// tuple
#if   IUTEST_HAS_VARIADIC_TEMPLATES
#  define IUTEST_HAS_STD_TUPLE			1
#elif (!defined(__CUDACC__) && !defined(__ARMCC_VERSION) && (IUTEST_LIBSTDCXX_VERSION >= 40000))
#  define IUTEST_HAS_TR1_TUPLE			1
#endif

#define IUTEST_HAS_HDR_CXXABI			1

#elif defined(_LIBCPP_VERSION)

// libc++
#if IUTEST_HAS_CXX11
#  define IUTEST_HAS_STD_BEGIN_END		1
#  define IUTEST_HAS_STD_DECLVAL		1
#  define IUTEST_HAS_STD_EMPLACE		1
#  define IUTEST_HAS_CXX_HDR_CHRONO		1
#  define IUTEST_HAS_CXX_HDR_REGEX		1
#  define IUTEST_HAS_CXX_HDR_RANDOM		1
#  define IUTEST_HAS_CXX_HDR_CODECVT	1
#endif

// tuple
#if   IUTEST_HAS_VARIADIC_TEMPLATES
#  define IUTEST_HAS_STD_TUPLE			1
#elif defined(__has_include)
#  if __has_include( <tr1/tuple> )
#    define IUTEST_HAS_TR1_TUPLE		1
#  endif
#endif

#define IUTEST_HAS_HDR_CXXABI			1

#elif defined(_MSC_VER) && defined(_MSC_FULL_VER)

// Visual C++

#if _MSC_VER >= 1700
#  define IUTEST_HAS_STD_BEGIN_END		1
#  define IUTEST_HAS_STD_DECLVAL		IUTEST_HAS_DECLTYPE
#  define IUTEST_HAS_STD_EMPLACE		1
#  define IUTEST_HAS_CXX_HDR_REGEX		1
#  define IUTEST_HAS_CXX_HDR_RANDOM		1
#  define IUTEST_HAS_CXX_HDR_CODECVT	1
#  if _MSC_FULL_VER != 190023725
#    define IUTEST_HAS_CXX_HDR_CHRONO	1
#  endif
#endif

// tuple
#if (_MSC_VER > 1700) || (_MSC_VER == 1700 && _VARIADIC_MAX >= 9)
#  define IUTEST_HAS_STD_TUPLE			1
#elif (_MSC_VER >= 1500) && (_MSC_VER < 1700) && (_MSC_FULL_VER > 150021022)
#  define IUTEST_HAS_TR1_TUPLE			1
#endif

#elif defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

// stlport

#endif

// iterator

//! has std::begin,std::end
#if !defined(IUTEST_HAS_STD_BEGIN_END)
#  define IUTEST_HAS_STD_BEGIN_END		0
#endif
//! has std::declval
#if !defined(IUTEST_HAS_STD_DECLVAL)
#  define IUTEST_HAS_STD_DECLVAL		0
#endif
//! use external include tr1::tuple
#if !defined(IUTEST_USE_EXTERNAL_TR1_TUPLE)
#  define IUTEST_USE_EXTERNAL_TR1_TUPLE	0
#endif
//! use external include std::tuple
#ifndef IUTEST_USE_EXTERNAL_STD_TUPLE
#  define IUTEST_USE_EXTERNAL_STD_TUPLE	0
#endif
//! has ::std::tuple
#if !defined(IUTEST_HAS_STD_TUPLE)
#  define IUTEST_HAS_STD_TUPLE			0
#endif
//! has ::std::tr1::tuple
#if !defined(IUTEST_HAS_TR1_TUPLE)
#  define IUTEST_HAS_TR1_TUPLE			0
#endif
//! has tuple
#if IUTEST_HAS_STD_TUPLE || IUTEST_HAS_TR1_TUPLE || IUTEST_USE_EXTERNAL_TR1_TUPLE || IUTEST_USE_EXTERNAL_STD_TUPLE
#  if !defined(IUTEST_HAS_TUPLE)
#    define IUTEST_HAS_TUPLE			1
#  endif
#else
#  if defined(IUTEST_HAS_TUPLE)
#    undef IUTEST_HAS_TUPLE
#  endif
#  define IUTEST_HAS_TUPLE				0
#endif
//! has chrono header
#if !defined(IUTEST_HAS_CXX_HDR_CHRONO)
#  define IUTEST_HAS_CXX_HDR_CHRONO		0
#endif
//! has regex header
#if !defined(IUTEST_HAS_CXX_HDR_REGEX)
#  define IUTEST_HAS_CXX_HDR_REGEX		0
#endif
//! has random header
#if !defined(IUTEST_HAS_CXX_HDR_RANDOM)
#  define IUTEST_HAS_CXX_HDR_RANDOM		0
#endif
//! has codecvt header
#if !defined(IUTEST_HAS_CXX_HDR_CODECVT)
#  define IUTEST_HAS_CXX_HDR_CODECVT	0
#endif
//! has emplace
#if !defined(IUTEST_HAS_STD_EMPLACE)
#  define IUTEST_HAS_STD_EMPLACE		0
#endif
//! has cxxabi header
#if !defined(IUTEST_HAS_HDR_CXXABI)
#  define IUTEST_HAS_HDR_CXXABI			0
#endif


//======================================================================
// decalre

//! using begin,end
#if !defined(IUTEST_USING_BEGIN_END)
#  if IUTEST_HAS_STD_BEGIN_END
#    define IUTEST_USING_BEGIN_END()	\
	using ::std::begin; using ::std::end
#  else
#    define IUTEST_USING_BEGIN_END()	\
	using ::iutest::detail::cxx::begin; using ::iutest::detail::cxx::end
#  endif
#endif

namespace iutest {
namespace detail {
namespace cxx
{

#if IUTEST_HAS_STD_BEGIN_END

using namespace std; // NOLINT

#else

template<typename T> typename T::iterator begin(T& x) { return x.begin(); }
template<typename T> typename T::iterator end  (T& x) { return x.end(); }

template<typename T> typename T::const_iterator begin(const T& x) { return x.begin(); }
template<typename T> typename T::const_iterator end  (const T& x) { return x.end(); }

#if !defined(IUTEST_NO_FUNCTION_TEMPLATE_ORDERING)
template<typename T, size_t SIZE> T* begin(T (&x)[SIZE]) { return &x[0]; }
template<typename T, size_t SIZE> T* end  (T (&x)[SIZE]) { return begin(x) + SIZE; }

template<typename T, size_t SIZE> const T* begin(const T (&x)[SIZE]) { return &x[0]; }
template<typename T, size_t SIZE> const T* end  (const T (&x)[SIZE]) { return begin(x) + SIZE; }
#endif

#endif

}	// end of namespace cxx
}	// end of namespace detail
}	// end of namespace iutest

#if IUTEST_HAS_TUPLE
#if !IUTEST_USE_EXTERNAL_STD_TUPLE && !IUTEST_USE_EXTERNAL_TR1_TUPLE
#  if   IUTEST_HAS_STD_TUPLE
#    include <tuple>
#  elif IUTEST_HAS_TR1_TUPLE
#    if (defined(__GNUC__) && (__GNUC__ >= 4))
#      include <tr1/tuple>
#    else
#      include <tuple>
#    endif
#  endif
#endif

namespace iutest {
namespace tuples
{

#if   IUTEST_HAS_STD_TUPLE
namespace alias = ::std;
#elif IUTEST_HAS_TR1_TUPLE
namespace alias = ::std::tr1;
#endif

using alias::tuple;
using alias::tuple_element;
using alias::make_tuple;
using alias::get;

template<typename T>struct tuple_size : public alias::tuple_size<T> {};
template<typename T>struct tuple_size<const T> : public alias::tuple_size<T> {};
template<typename T>struct tuple_size<volatile T> : public alias::tuple_size<T>{};
template<typename T>struct tuple_size<const volatile T> : public alias::tuple_size<T>{};

namespace detail
{

template<typename T, typename F, int Begin>
struct tuple_foreach_impl
{
	template<int N, int I>
	struct impl
	{
		static void do_something(T& t, F fn)
		{
			fn(I, get<I>(t));
			impl<N, I + 1>::do_something(t, fn);
		}
	};
	template<int N>
	struct impl<N, N>
	{
		static void do_something(T&, F) {}
	};

	static void do_something(T& t, F fn)
	{
		impl<tuple_size<T>::value, Begin>::do_something(t, fn);
	}
};

template<typename T, typename U>
struct tuple_cast_copy_impl
{
	template<int N, int I>
	struct impl
	{
		static void copy(T& dst, const U& src)
		{
			get<I>(dst) = static_cast<typename tuple_element<I, T>::type>(get<I>(src));
			impl<N, I + 1>::copy(dst, src);
		}
	};
	template<int N>
	struct impl<N, N>
	{
		static void copy(T&, const U&) {}
	};

	static void copy(T& dst, const U& src)
	{
		impl<tuple_size<T>::value, 0>::copy(dst, src);
	}
};

}	// end of namespace detail

template<int I, typename tuple_t, typename F>
void tuple_foreach(tuple_t& t, F& fn)
{
	detail::tuple_foreach_impl<tuple_t, F&, I>::do_something(t, fn);
}
template<typename tuple_t, typename F>
void tuple_foreach(tuple_t& t, F& fn)
{
	tuple_foreach<0>(t, fn);
}
template<int I, typename tuple_t, typename F>
void tuple_foreach(tuple_t& t, const F& fn)
{
	detail::tuple_foreach_impl<tuple_t, const F&, I>::do_something(t, fn);
}
template<typename tuple_t, typename F>
void tuple_foreach(tuple_t& t, const F& fn)
{
	tuple_foreach<0>(t, fn);
}
template<typename T, typename U>
void tuple_cast_copy(T& dst, const U& src)
{
	detail::tuple_cast_copy_impl<T, U>::copy(dst, src);
}

}	// end of namespace tuples

using tuples::tuple;
using tuples::tuple_size;
using tuples::tuple_element;
using tuples::tuple_foreach;
using tuples::make_tuple;
using tuples::get;

}	// end of namespace iutest

#endif

//! has uchar
#if !defined(IUTEST_HAS_HDR_UCHAR)
#  if IUTEST_HAS_CHAR16_T || IUTEST_HAS_CHAR32_T
#    if   defined(__has_include)
#      if __has_include( <uchar.h> )
#        define IUTEST_HAS_HDR_UCHAR			1
#      endif
#    elif defined(_MSC_VER)
#      define IUTEST_HAS_HDR_UCHAR				1
#    endif
#  endif
#endif

#if !defined(IUTEST_HAS_HDR_UCHAR)
#  define IUTEST_HAS_HDR_UCHAR			0
#endif

//! has sys/time.h header
#if !defined(IUTEST_HAS_HDR_SYSTIME)
#  if defined(IUTEST_OS_WINDOWS) && !defined(IUTEST_OS_WINDOWS_MINGW) && !defined(IUTEST_OS_WINDOWS_WINE)
#    define IUTEST_HAS_HDR_SYSTIME		0
#  endif
#endif

#if !defined(IUTEST_HAS_HDR_SYSTIME)
#  define IUTEST_HAS_HDR_SYSTIME		1
#endif

// socklen_t
#if defined(IUTEST_OS_WINDOWS_WINE)
#  define __socklen_t_defined
#endif

//! std::stringstream が使用可能かどうか
#if !defined(IUTEST_HAS_STRINGSTREAM)
#  if !defined(_STLP_NO_IOSTREAMS)
#    define IUTEST_HAS_STRINGSTREAM	1
#  endif
#endif

#if !defined(IUTEST_HAS_STRINGSTREAM)
#  define IUTEST_HAS_STRINGSTREAM	0
#endif


/**
 * @brief	std::strstream が使用可能かどうか
 * @note	IUTEST_HAS_STRINGSTREAM が優先されます
*/
#if !defined(IUTEST_HAS_STRSTREAM)
#  define IUTEST_HAS_STRSTREAM		0
#endif

namespace iutest {
namespace detail
{

//======================================================================
// function
/**
 * @internal
 * @brief	mbtowc
*/
inline int iu_mbtowc(wchar_t* dst, const char* src, size_t size)
{
#if defined(IUTEST_OS_LINUX_ANDROID) || defined(IUTEST_OS_WINDOWS_MOBILE)
	// unimplimented
	IUTEST_UNUSED_VAR(dst);
	IUTEST_UNUSED_VAR(src);
	IUTEST_UNUSED_VAR(size);
	return 0;
#else
	return mbtowc(dst, src, size);
#endif
}

}	// end of namespace detail
}	// end of namespace iutest

#endif // INCG_IRIS_IUTEST_STDLIB_HPP_54D4BEEE_7B6B_4AF4_B1F6_138560480D55_

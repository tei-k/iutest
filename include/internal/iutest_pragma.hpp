﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_pragma.hpp
 * @brief		iris unit test pragma 依存の吸収 ファイル
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_PRAGMA_HPP_FBC5A1DE_3D0C_443E_84B1_5F0618DF9A6B_
#define INCG_IRIS_IUTEST_PRAGMA_HPP_FBC5A1DE_3D0C_443E_84B1_5F0618DF9A6B_

//======================================================================
// define

// pragma
#if   defined(_MSC_VER) && _MSC_VER >= 1310
#  define IUTEST_PRAGMA(x)	__pragma(x)
#elif defined(__GNUC__)
#  define IUTEST_PRAGMA(x)	_Pragma(#x)
#elif defined(__clang__)
#  define IUTEST_PRAGMA(x)	_Pragma(#x)
#else
#  define IUTEST_PRAGMA(x)
#endif

#define IUTEST_PRAGMA_MESSAGE(m)	IUTEST_PRAGMA(message (m))

// pragma warning
#if defined(_MSC_VER)
#  define IUTEST_PRAGMA_MSC_WARN_PUSH()			IUTEST_PRAGMA(warning (push))
#  define IUTEST_PRAGMA_MSC_WARN_DISABLE(x)		IUTEST_PRAGMA(warning (disable: x))
#  define IUTEST_PRAGMA_MSC_WARN_SUPPRESS(x)	IUTEST_PRAGMA(warning (suppress: x))
#  define IUTEST_PRAGMA_MSC_WARN_POP()			IUTEST_PRAGMA(warning (pop))
#endif

#if defined(__GNUC__)
#  if ((__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#    define IUTEST_PRAGMA_GCC_WARN_PUSH()		IUTEST_PRAGMA(GCC diagnostic push)
#    define IUTEST_PRAGMA_GCC_WARN_DISABLE(x)	IUTEST_PRAGMA(GCC diagnostic ignored x)
#    define IUTEST_PRAGMA_GCC_WARN_POP()		IUTEST_PRAGMA(GCC diagnostic pop)
#  else
#    define IUTEST_PRAGMA_GCC_WARN_PUSH()
#    define IUTEST_PRAGMA_GCC_WARN_DISABLE(x)
#    define IUTEST_PRAGMA_GCC_WARN_POP()
#  endif
#endif

#if defined(__clang__)
#  define IUTEST_PRAGMA_CLANG_WARN_PUSH()		IUTEST_PRAGMA(clang diagnostic push)
#  define IUTEST_PRAGMA_CLANG_WARN_DISABLE(x)	IUTEST_PRAGMA(clang diagnostic ignored x)
#  define IUTEST_PRAGMA_CLANG_WARN_POP()		IUTEST_PRAGMA(clang diagnostic pop)
#  if defined(__GNUC__)
#    undef IUTEST_PRAGMA_GCC_WARN_PUSH
#    undef IUTEST_PRAGMA_GCC_WARN_DISABLE
#    undef IUTEST_PRAGMA_GCC_WARN_POP
#  endif
#  define IUTEST_PRAGMA_GCC_WARN_PUSH			IUTEST_PRAGMA_CLANG_WARN_PUSH
#  define IUTEST_PRAGMA_GCC_WARN_DISABLE		IUTEST_PRAGMA_CLANG_WARN_DISABLE
#  define IUTEST_PRAGMA_GCC_WARN_POP			IUTEST_PRAGMA_CLANG_WARN_POP
#endif

#ifndef IUTEST_PRAGMA_MSC_WARN_PUSH
#  define IUTEST_PRAGMA_MSC_WARN_PUSH()
#endif
#ifndef IUTEST_PRAGMA_MSC_WARN_DISABLE
#  define IUTEST_PRAGMA_MSC_WARN_DISABLE(x)
#endif
#ifndef IUTEST_PRAGMA_MSC_WARN_POP
#  define IUTEST_PRAGMA_MSC_WARN_POP()
#endif

#ifndef IUTEST_PRAGMA_GCC_WARN_PUSH
#  define IUTEST_PRAGMA_GCC_WARN_PUSH()
#endif
#ifndef IUTEST_PRAGMA_GCC_WARN_DISABLE
#  define IUTEST_PRAGMA_GCC_WARN_DISABLE(x)
#endif
#ifndef IUTEST_PRAGMA_GCC_WARN_POP
#  define IUTEST_PRAGMA_GCC_WARN_POP()
#endif

#ifndef IUTEST_PRAGMA_CLANG_WARN_PUSH
#  define IUTEST_PRAGMA_CLANG_WARN_PUSH()
#endif
#ifndef IUTEST_PRAGMA_CLANG_WARN_DISABLE
#  define IUTEST_PRAGMA_CLANG_WARN_DISABLE(x)
#endif
#ifndef IUTEST_PRAGMA_CLANG_WARN_POP
#  define IUTEST_PRAGMA_CLANG_WARN_POP()
#endif

#if   defined(__clang__)
#  define IUTEST_PARGMA_WARN_PUSH()		IUTEST_PRAGMA_CLANG_WARN_PUSH()
#  define IUTEST_PARGMA_WARN_POP()		IUTEST_PRAGMA_CLANG_WARN_PUSH()
#elif defined(__GNUC__)
#  define IUTEST_PARGMA_WARN_PUSH()		IUTEST_PRAGMA_GCC_WARN_PUSH()
#  define IUTEST_PARGMA_WARN_POP()		IUTEST_PRAGMA_GCC_WARN_POP()
#elif defined(_MSC_VER)
#  define IUTEST_PARGMA_WARN_PUSH()		IUTEST_PRAGMA_MSC_WARN_PUSH()
#  define IUTEST_PARGMA_WARN_POP()		IUTEST_PRAGMA_MSC_WARN_POP()
#else
#  define IUTEST_PARGMA_WARN_PUSH()
#  define IUTEST_PARGMA_WARN_POP()
#endif


// pragma warning xxx
#if defined(_MSC_VER) && defined(__STDC_WANT_SECURE_LIB__) && __STDC_WANT_SECURE_LIB__
#  if defined(__clang__)
#    define IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()	IUTEST_PRAGMA_CLANG_WARN_PUSH()	\
															IUTEST_PRAGMA_CLANG_WARN_DISABLE("-Wdeprecated-declarations")
#    define IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()		IUTEST_PRAGMA_CLANG_WARN_POP()
#  else
#    define IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()	IUTEST_PRAGMA_MSC_WARN_PUSH()	\
															IUTEST_PRAGMA_MSC_WARN_DISABLE(4996)
#    define IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()		IUTEST_PRAGMA_MSC_WARN_POP()
#  endif
#else
#  define IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()
#  define IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()
#endif

#if defined(_MSC_VER) && _MSC_VER < 1700
#  define IUTEST_PRAGMA_EXTERN_TEMPLATE_WARN_DISABLE_BEGIN()	IUTEST_PRAGMA_MSC_WARN_PUSH()	\
																IUTEST_PRAGMA_MSC_WARN_DISABLE(4231)
#  define IUTEST_PRAGMA_EXTERN_TEMPLATE_WARN_DISABLE_END()		IUTEST_PRAGMA_MSC_WARN_POP()
#else
#  define IUTEST_PRAGMA_EXTERN_TEMPLATE_WARN_DISABLE_BEGIN()
#  define IUTEST_PRAGMA_EXTERN_TEMPLATE_WARN_DISABLE_END()
#endif

#if defined(_MSC_VER) && IUTEST_HAS_CONSTEXPR
#  define IUTEST_PRAGMA_CONSTEXPR_CALLED_AT_RUNTIME_WARN_DISABLE_BEGIN()	IUTEST_PRAGMA_MSC_WARN_PUSH()	\
																			IUTEST_PRAGMA_MSC_WARN_DISABLE(4592)
#  define IUTEST_PRAGMA_CONSTEXPR_CALLED_AT_RUNTIME_WARN_DISABLE_END()		IUTEST_PRAGMA_MSC_WARN_POP()
#else
#  define IUTEST_PRAGMA_CONSTEXPR_CALLED_AT_RUNTIME_WARN_DISABLE_BEGIN()
#  define IUTEST_PRAGMA_CONSTEXPR_CALLED_AT_RUNTIME_WARN_DISABLE_END()
#endif


#if   defined(_MSC_VER)
#  define IUTEST_PRAGMA_WARN_DISABLE_SIGN_COMPARE()	IUTEST_PRAGMA(warning (disable:4389 4018))
#elif defined(__clang__)
#  define IUTEST_PRAGMA_WARN_DISABLE_SIGN_COMPARE()	IUTEST_PRAGMA_CLANG_WARN_DISABLE("-Wsign-compare")
#elif defined(__GNUC__)
#  define IUTEST_PRAGMA_WARN_DISABLE_SIGN_COMPARE()	IUTEST_PRAGMA_GCC_WARN_DISABLE("-Wsign-compare")
#else
#  define IUTEST_PRAGMA_WARN_DISABLE_SIGN_COMPARE()
#endif

#if   defined(_MSC_VER)
#  define IUTEST_PRAGMA_WARN_DISABLE_EMPTY_BODY()	IUTEST_PRAGMA(warning (disable:4390))
#elif defined(__clang__)
#  define IUTEST_PRAGMA_WARN_DISABLE_EMPTY_BODY()	IUTEST_PRAGMA_CLANG_WARN_DISABLE("-Wempty-body")
#elif defined(__GNUC__)
#  define IUTEST_PRAGMA_WARN_DISABLE_EMPTY_BODY()	IUTEST_PRAGMA_GCC_WARN_DISABLE("-Wempty-body")
#else
#  define IUTEST_PRAGMA_WARN_DISABLE_EMPTY_BODY()
#endif

#endif // INCG_IRIS_IUTEST_PRAGMA_HPP_FBC5A1DE_3D0C_443E_84B1_5F0618DF9A6B_

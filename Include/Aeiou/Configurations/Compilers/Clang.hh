/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_COMPILERS_CLANG_HH
#define AEIOU_HEADER_CONFIGURATIONS_COMPILERS_CLANG_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler-Values.hh>

#ifdef AEIOU_CONFIG_COMPILER
#error "Compiler configuration is invalid."
#endif

#define AEIOU_CONFIG_COMPILER AEIOU_CONFIG_CLANG

#define AEIOU_CONFIG_SUPPORTED_LINUX AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_WINDOWS AEIOU_CONFIG_YES

#define AEIOU_CONFIG_SUPPORTED_LONGLONG AEIOU_CONFIG_YES

#if (__clang_major__ == 3 && __clang_minor__ >= 1) || __clang_major__ > 3 // clang 3.1
#define AEIOU_CONFIG_SUPPORTED_CONSTEXPR		AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_CONSTEXPR		AEIOU_CONFIG_NO
#endif

#if (__clang_major__ == 3 && __clang_minor__ >= 0) || __clang_major__ > 3 // clang 3.0
#define AEIOU_CONFIG_SUPPORTED_DELETE			AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_NOEXCEPT			AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_DELETE			AEIOU_CONFIG_NO
#define AEIOU_CONFIG_SUPPORTED_NOEXCEPT			AEIOU_CONFIG_NO
#endif

#if (__clang_major__ == 2 && __clang_minor__ >= 9) || __clang_major__ > 2 // clang 2.9
#define AEIOU_CONFIG_SUPPORTED_FINAL			AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_NEW_CHAR			AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT		AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_FINAL			AEIOU_CONFIG_NO
#define AEIOU_CONFIG_SUPPORTED_NEW_CHAR			AEIOU_CONFIG_NO
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT		AEIOU_CONFIG_NO
#endif

#endif
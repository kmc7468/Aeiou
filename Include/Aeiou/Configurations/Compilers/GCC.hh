/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_COMPILERS_GCC_HH
#define AEIOU_HEADER_CONFIGURATIONS_COMPILERS_GCC_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler-Values.hh>

#ifdef AEIOU_CONFIG_COMPILER
#error "Compiler configuration is invalid."
#endif

#define AEIOU_CONFIG_COMPILER AEIOU_CONFIG_GCC

#define AEIOU_CONFIG_SUPPORTED_LINUX AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_WINDOWS AEIOU_CONFIG_YES

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 7) || __GNUC__ > 4 // gcc 4.7
#define AEIOU_CONFIG_SUPPORTED_FINAL			AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_FINAL			AEIOU_CONFIG_NO
#endif

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 6) || __GNUC__ > 4 // gcc 4.7
#define AEIOU_CONFIG_SUPPORTED_CONSTEXPR	AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_CONSTEXPR		AEIOU_CONFIG_NO
#endif

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 3) || __GNUC__ > 4 // gcc 4.3
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT		AEIOU_CONFIG_NO
#endif

#endif
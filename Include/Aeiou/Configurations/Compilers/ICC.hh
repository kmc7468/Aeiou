/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_COMPILERS_ICC_HH
#define AEIOU_HEADER_CONFIGURATIONS_COMPILERS_ICC_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler-Values.hh>

#ifdef AEIOU_CONFIG_COMPILER
#error "Compiler configuration is invalid."
#endif

#define AEIOU_CONFIG_COMPILER AEIOU_CONFIG_ICC

#define AEIOU_CONFIG_SUPPORTED_LINUX AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_WINDOWS AEIOU_CONFIG_YES

#define AEIOU_CONFIG_SUPPORTED_LONGLONG AEIOU_CONFIG_YES

#if ((__INTEL_COMPILER / 100) == 14 && (__INTEL_COMPILER % 100 / 10) >= 0) || \
(__INTEL_COMPILER / 100) > 14 // ICC 14.0
#define AEIOU_CONFIG_SUPPORTED_NOEXCEPT			AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_NOEXCEPT			AEIOU_CONFIG_NO
#endif

#if ((__INTEL_COMPILER / 100) == 13 && (__INTEL_COMPILER % 100 / 10) >= 0) || \
(__INTEL_COMPILER / 100) > 13 // ICC 13.0
#define AEIOU_CONFIG_SUPPORTED_CONSTEXPR		AEIOU_CONFIG_YES
#define AEIOU_CONFIG_SUPPORTED_DELETE			AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_CONSTEXPR		AEIOU_CONFIG_NO
#define AEIOU_CONFIG_SUPPORTED_DELETE			AEIOU_CONFIG_NO
#endif

#if ((__INTEL_COMPILER / 100) == 12 && (__INTEL_COMPILER % 100 / 10) >= 1) || \
(__INTEL_COMPILER / 100) > 12 // ICC 12.1
#define AEIOU_CONFIG_SUPPORTED_NEW_CHAR			AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_NEW_CHAR			AEIOU_CONFIG_NO
#endif

#if ((__INTEL_COMPILER / 100) == 12 && (__INTEL_COMPILER % 100 / 10) >= 0) || \
(__INTEL_COMPILER / 100) > 12 // ICC 12.0
#define AEIOU_CONFIG_SUPPORTED_FINAL			AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_FINAL			AEIOU_CONFIG_NO
#endif

#if ((__INTEL_COMPILER / 100) == 11 && (__INTEL_COMPILER % 100 / 10) >= 0) || \
(__INTEL_COMPILER / 100) > 11 // ICC 11.0
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT		AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT		AEIOU_CONFIG_NO
#endif

#endif
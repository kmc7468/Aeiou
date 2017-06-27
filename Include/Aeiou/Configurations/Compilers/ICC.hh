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

#if ((__INTEL_COMPILER / 100) == 11 && (__INTEL_COMPILER % 100 / 10) >= 0) || \
(__INTEL_COMPILER / 100) > 11 // ICC 11.0
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT AEIOU_CONFIG_NO
#endif

#endif
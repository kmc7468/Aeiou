/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_COMPILERS_MSVC_HH
#define AEIOU_HEADER_CONFIGURATIONS_COMPILERS_MSVC_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler-Values.hh>

#ifdef AEIOU_CONFIG_COMPILER
#error "Compiler configuration is invalid."
#endif

#define AEIOU_CONFIG_COMPILER AEIOU_CONFIG_MSVC

#define AEIOU_CONFIG_SUPPORTED_LINUX AEIOU_CONFIG_NO
#define AEIOU_CONFIG_SUPPORTED_WINDOWS AEIOU_CONFIG_YES

#if _MSC_VER >= 1600 // MSVC 2010
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT AEIOU_CONFIG_YES
#else
#define AEIOU_CONFIG_SUPPORTED_STATICASSERT AEIOU_CONFIG_NO
#endif

#endif
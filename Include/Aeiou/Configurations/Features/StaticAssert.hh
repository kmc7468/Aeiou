/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_FEATURES_STATICASSERT_HH
#define AEIOU_HEADER_CONFIGURATIONS_FEATURES_STATICASSERT_HH
#include <Aeiou/Configurations/Basic-Values.hh>

#include <Aeiou/Configurations/Compiler.hh>

#if AEIOU_CONFIG_SUPPORTED_STATICASSERT == AEIOU_CONFIG_YES
#define AEIOU_STATIC_ASSERT(condition, message) static_assert((condition), message)
#else
#define AEIOU_STATIC_ASSERT(condition, message) \
typedef unsigned char AEIOU_STATIC_ASSERT_##message[(condition) ? 1 : -1]
#endif

#endif
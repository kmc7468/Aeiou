/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_UTILITIES_ALWAYSINLINE_HH
#define AEIOU_HEADER_UTILITIES_ALWAYSINLINE_HH
#include <Aeiou/Configurations.hh>

#if AEIOU_CONFIG_COMPILER == AEIOU_CONFIG_MSVC
#define AEIOU_ALWAYS_INLINE __forceinline
#else
#define AEIOU_ALWAYS_INLINE __attribute__((always_inline))
#endif

#endif
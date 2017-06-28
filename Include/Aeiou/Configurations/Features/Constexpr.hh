/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_FEATURES_CONSTEXPR_HH
#define AEIOU_HEADER_CONFIGURATIONS_FEATURES_CONSTEXPR_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler.hh>

#if AEIOU_CONFIG_SUPPORTED_CONSTEXPR == AEIOU_CONFIG_YES
#define AEIOU_CONSTEXPR			constexpr
#else
#define AEIOU_CONSTEXPR
#endif

#endif
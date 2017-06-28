/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_FEATURES_NOEXCEPT_HH
#define AEIOU_HEADER_CONFIGURATIONS_FEATURES_NOEXCEPT_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler.hh>

#if AEIOU_CONFIG_SUPPORTED_NOEXCEPT == AEIOU_CONFIG_YES
#define AEIOU_NOEXCEPT noexcept
#else
#define AEIOU_NOEXCEPT throw()
#endif

#endif
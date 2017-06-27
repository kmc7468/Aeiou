/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_PLATFORM_HH
#define AEIOU_HEADER_CONFIGURATIONS_PLATFORM_HH
#include <Aeiou/Configurations/Basic-Values.hh>
#include <Aeiou/Configurations/Compiler.hh>

#if defined(__linux__) || defined(__linux) || defined(linux)
#if LUCE_CONFIG_SUPPORTED_LINUX == LUCE_CONFIG_YES
#include <Aeiou/Configurations/Platforms/Linux.hh>
#else
#error "Platform not supported."
#endif
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
#if LUCE_CONFIG_SUPPORTED_WINDOWS == LUCE_CONFIG_YES
#include <Aeiou/Configurations/Platforms/Windows.hh>
#else
#error "Platform not supported."
#endif
#else
#error "Platform not supported."
#endif

#endif
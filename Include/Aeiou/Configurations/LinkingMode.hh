/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_LINKINGMODE_HH
#define AEIOU_HEADER_CONFIGURATIONS_LINKINGMODE_HH
#include <Aeiou/Configurations/Compiler.hh>
#include <Aeiou/Configurations/LinkingMode-Values.hh>

#ifdef AEIOU_CONFIG_LINKING_MODE
#error "Linking mode configuration is invalid."
#endif

#if AEIOU_CONFIG_COMPILER == AEIOU_CONFIG_MSVC && defined(AEIOU_DYNAMIC)
#ifdef AEIOU
#define AEIOU_EXPORT __declspec(dllexport)
#else
#define AEIOU_EXPORT __declspec(dllimport)
#endif
#else
#define AEIOU_EXPORT
#endif

#ifdef AEIOU_DYNAMIC
#define AEIOU_CONFIG_LINKING_MODE AEIOU_CONFIG_SHARED
#else
#define AEIOU_CONFIG_LINKING_MODE AEIOU_CONFIG_STATIC
#endif

#endif
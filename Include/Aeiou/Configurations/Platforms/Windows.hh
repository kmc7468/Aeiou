/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_PLATFORMS_WINDOWS_HH
#define AEIOU_HEADER_CONFIGURATIONS_PLATFORMS_WINDOWS_HH
#include <Aeiou/Configurations/Platform-Values.hh>

#ifdef AEIOU_CONFIG_PLATFORM
#error "Platform configuration is invalid."
#endif

#define AEIOU_CONFIG_PLATFORM AEIOU_CONFIG_WINDOWS

#endif
/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_PREPROCESSOR_CONFIGURATIONS_DATALIMIT_HH
#define AEIOU_HEADER_PREPROCESSOR_CONFIGURATIONS_DATALIMIT_HH
#include <Aeiou/Preprocessor/Configurations/DataLimit-Values.hh>

#ifdef AEIOU_CONFIG_PP_DATALIMIT
#error "Data limit configuration is invalid."
#endif

#ifdef AEIOU_PP_2BYTE
#define AEIOU_CONFIG_PP_DATALIMIT AEIOU_CONFIG_PP_2BYTE
#else
#define AEIOU_CONFIG_PP_DATALIMIT AEIOU_CONFIG_PP_1BYTE
#endif

#endif
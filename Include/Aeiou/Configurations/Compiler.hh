/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_CONFIGURATIONS_COMPILER_HH
#define AEIOU_HEADER_CONFIGURATIONS_COMPILER_HH

#if defined(__clang__)
#include <Aeiou/Configurations/Compilers/Clang.hh>
#elif defined(__GNUC__)
#include <Aeiou/Configurations/Compilers/GCC.hh>
#elif defined(__ICC) || defined(__ICL)
#include <Aeiou/Configurations/Compilers/ICC.hh>
#elif defined(_MSC_VER)
#include <Aeiou/Configurations/Compilers/MSVC.hh>
#else
#error "Compiler not supported."
#endif

#include <Aeiou/Configurations/Features.hh>
#endif
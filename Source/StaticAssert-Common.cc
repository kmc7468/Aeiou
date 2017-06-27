/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#include <Aeiou/Configurations.hh>
#include <Aeiou/Preprocessor/Features-Supported.hh>

#include <climits>

#ifdef AEIOU_SUPPORTED_STATIC_ASSERT
AEIOU_STATIC_ASSERT(sizeof(void*) * CHAR_BIT >= 16,
					"Only 16-bit and higher systems are supported.");

AEIOU_STATIC_ASSERT(CHAR_BIT == 8,
					"Only systems with 8-bits per byte are supported.");

AEIOU_STATIC_ASSERT(sizeof(float) == 4 && sizeof(double) == 8,
					"Only systems with a float of 4 bytes and "
					"a double of 8 bytes are supported.");
#else
AEIOU_STATIC_ASSERT(sizeof(void*) * CHAR_BIT >= 16,
					Only_16_bit_and_higher_systems_are_supported);

AEIOU_STATIC_ASSERT(CHAR_BIT == 8,
					Only_systems_with_8_bits_per_byte_are_supported);

AEIOU_STATIC_ASSERT(sizeof(float) == 4 && sizeof(double) == 8,
					Only_systems_with_a_float_of_4_bytes_and_a_double_of_8_bytes_are_supported);
#endif
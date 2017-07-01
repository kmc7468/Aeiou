/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_UTILITIES_INTEGER_HH
#define AEIOU_HEADER_UTILITIES_INTEGER_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Preprocessor/Features-Supported.hh>
#include <Aeiou/TypeTraits/MakeSigned.hh>
#include <Aeiou/TypeTraits/MakeUnsigned.hh>
#include <Aeiou/TypeTraits/SelectIf.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

#include <climits>
#include <cstddef>

namespace Aeiou
{
	namespace Utilities
	{
#if UCHAR_MAX == 255
		typedef signed char Int8_t;
		typedef unsigned char UInt8_t;
#else
#error "Platform not supported."
#endif

#if USHRT_MAX == 65535
		typedef signed short Int16_t;
		typedef unsigned short UInt16_t;
#elif UINT_MAX == 65535
		typedef signed int Int16_t;
		typedef unsigned int UInt16_t;
#else
#error "Platform not supported."
#endif

#if USHRT_MAX == 4294967295
		typedef signed short Int32_t;
		typedef unsigned short Int32_t;
#elif UINT_MAX == 4294967295
		typedef signed int Int32_t;
		typedef unsigned int UInt32_t;
#elif ULONG_MAX == 4294967295
		typedef signed long Int32_t;
		typedef unsigned long UInt32_t;
#else
#error "Platform not supported."
#endif

#ifdef AEIOU_SUPPORTED_LONGLONG
#if USHRT_MAX == 18446744073709551615
		typedef signed short Int64_t;
		typedef unsigned short UInt64_t;
#elif UINT_MAX == 18446744073709551615
		typedef signed int Int64_t;
		typedef unsigned int UInt64_t;
#elif ULONG_MAX == 18446744073709551615
		typedef signed long Int64_t;
		typedef unsigned long UInt64_t;
#elif ULLONG_MAX == 18446744073709551615
		typedef signed long long Int64_t;
		typedef unsigned long long UInt64_t;
#else
#error "Platform not supported."
#endif
#define AEIOU_INTEGER_MAX_BIT 64
#define AEIOU_INTEGER_MAX_64
		typedef Int64_t IntMax_t;
		typedef UInt64_t UIntMax_t;
#else
#define AEIOU_INTEGER_MAX_BIT 32
#define AEIOU_INTEGER_MAX_32
		typedef Int32_t IntMax_t;
		typedef UInt32_t UIntMax_t;
#endif

		namespace Details
		{
			typedef typename TypeTraits::SelectIf<sizeof(void*) == 2, Int16_t,
				typename TypeTraits::SelectIf<sizeof(void*) == 4, Int32_t,
				typename TypeTraits::SelectIf<sizeof(void*) == 8, Int64_t, void>
				::Type>::Type>::Type IntPtr_Original_t_;
		}

		typedef TypeTraits::MakeSigned<Details::IntPtr_Original_t_>::Type IntPtr_t;
		typedef TypeTraits::MakeUnsigned<Details::IntPtr_Original_t_>::Type UIntPtr_t;
		typedef IntPtr_t IntFast_t;
		typedef UIntPtr_t UIntFast_t;
	}

	using Utilities::Int8_t;
	using Utilities::UInt8_t;
	using Utilities::Int16_t;
	using Utilities::UInt16_t;
	using Utilities::Int32_t;
	using Utilities::UInt32_t;
#ifdef AEIOU_INTEGER_MAX_64
	using Utilities::Int64_t;
	using Utilities::UInt64_t;
#endif
	using Utilities::IntMax_t;
	using Utilities::UIntMax_t;
	using Utilities::IntPtr_t;
	using Utilities::UIntPtr_t;
	using Utilities::IntFast_t;
	using Utilities::UIntFast_t;
}

#endif
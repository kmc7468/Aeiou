/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISINTEGER_HH
#define AEIOU_HEADER_TYPETRAITS_ISINTEGER_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Preprocessor/Features-Supported.hh>
#include <Aeiou/TypeTraits/IsEqual.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsInteger AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(IsInteger)

		public:
			AEIOU_CONSTEXPR static const bool Value =
				IsEqual<typename RemoveCV<Ty_>::Type, bool				>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, char				>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, signed char		>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, unsigned char		>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, wchar_t			>::Value ||
#ifdef AEIOU_SUPPORTED_NEW_CHAR
				IsEqual<typename RemoveCV<Ty_>::Type, char16_t			>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, char32_t			>::Value ||
#endif
				IsEqual<typename RemoveCV<Ty_>::Type, signed short		>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, unsigned short	>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, signed int		>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, unsigned int		>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, signed long		>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, unsigned long		>::Value
#ifdef AEIOU_SUPPORTED_LONGLONG
				||
				IsEqual<typename RemoveCV<Ty_>::Type, signed long long	>::Value ||
				IsEqual<typename RemoveCV<Ty_>::Type, unsigned long long>::Value
#endif
				;
		};
	}

	using TypeTraits::IsInteger;
}

#endif
/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISARITHMETIC_HH
#define AEIOU_HEADER_TYPETRAITS_ISARITHMETIC_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/IsFloatingPoint.hh>
#include <Aeiou/TypeTraits/IsInteger.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsArithmetic AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(IsArithmetic)

		public:
			AEIOU_CONSTEXPR static const bool Value =
				IsFloatingPoint<Ty_>::Value || IsInteger<Ty_>::Value;
		};
	}

	using TypeTraits::IsArithmetic;
}

#endif
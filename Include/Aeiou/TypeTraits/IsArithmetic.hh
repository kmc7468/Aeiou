/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISARITHMETIC_HH
#define AEIOU_HEADER_TYPETRAITS_ISARITHMETIC_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/Constant.hh>
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
			: public Constant<bool, IsFloatingPoint<Ty_>::Value || IsInteger<Ty_>::Value>
		{
			AEIOU_NON_INHERITABLE(IsArithmetic)
		};
	}

	using TypeTraits::IsArithmetic;
}

#endif
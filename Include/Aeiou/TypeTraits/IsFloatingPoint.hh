/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISFLOATINGPOINT_HH
#define AEIOU_HEADER_TYPETRAITS_ISFLOATINGPOINT_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/Constant.hh>
#include <Aeiou/TypeTraits/IsEqual.hh>
#include <Aeiou/TypeTraits/RemoveCV.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsFloatingPoint AEIOU_FINAL
			: public Constant<bool,
			IsEqual<typename RemoveCV<Ty_>::Type, float		 >::Value ||
			IsEqual<typename RemoveCV<Ty_>::Type, double	 >::Value ||
			IsEqual<typename RemoveCV<Ty_>::Type, long double>::Value>
		{
			AEIOU_NON_INHERITABLE(IsFloatingPoint)
		};
	}

	using TypeTraits::IsFloatingPoint;
}

#endif
/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISVOID_HH
#define AEIOU_HEADER_TYPETRAITS_ISVOID_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/IsEqual.hh>
#include <Aeiou/TypeTraits/RemoveCV.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsVoid AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(IsVoid)

		public:
			AEIOU_CONSTEXPR static const bool Value =
				IsEqual<typename RemoveCV<Ty_>::Type, void>::Value;
		};
	}

	using TypeTraits::IsVoid;
}

#endif
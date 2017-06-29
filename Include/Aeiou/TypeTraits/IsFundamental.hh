/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISFUNDAMENTAL_HH
#define AEIOU_HEADER_TYPETRAITS_ISFUNDAMENTAL_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/IsArithmetic.hh>
#include <Aeiou/TypeTraits/IsPointer.hh>
#include <Aeiou/TypeTraits/IsVoid.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsFundamental AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(IsFundamental)

		public:
			AEIOU_CONSTEXPR static const bool Value =
				IsArithmetic<Ty_>::Value || IsPointer<Ty_>::Value || IsVoid<Ty_>::Value;
		};
	}

	using TypeTraits::IsFundamental;
}

#endif
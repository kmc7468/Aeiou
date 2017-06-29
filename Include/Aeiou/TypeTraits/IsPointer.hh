/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISPOINTER_HH
#define AEIOU_HEADER_TYPETRAITS_ISPOINTER_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsPointer AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(IsPointer)

		public:
			AEIOU_CONSTEXPR static const bool Value = false;
		};
		template<typename Ty_>
		class IsPointer<Ty_*> AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(IsPointer)

		public:
			AEIOU_CONSTEXPR static const bool Value = true;
		};
	}

	using TypeTraits::IsPointer;
}

#endif
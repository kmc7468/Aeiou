/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISPOINTER_HH
#define AEIOU_HEADER_TYPETRAITS_ISPOINTER_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/Constant.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class IsPointer AEIOU_FINAL
			: public False_t
		{
			AEIOU_NON_INHERITABLE(IsPointer)
		};
		template<typename Ty_>
		class IsPointer<Ty_*> AEIOU_FINAL
			: public True_t
		{
			AEIOU_NON_INHERITABLE(IsPointer)
		};
	}

	using TypeTraits::IsPointer;
}

#endif
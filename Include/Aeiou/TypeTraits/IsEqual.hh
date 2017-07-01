/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ISEQUAL_HH
#define AEIOU_HEADER_TYPETRAITS_ISEQUAL_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/Constant.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Left_, typename Right_>
		class IsEqual AEIOU_FINAL
			: public False_t
		{
			AEIOU_NON_INHERITABLE(IsEqual)
		};
		template<typename Ty_>
		class IsEqual<Ty_, Ty_> AEIOU_FINAL
			: public True_t
		{
			AEIOU_NON_INHERITABLE(IsEqual)
		};
	}

	using TypeTraits::IsEqual;
}

#endif
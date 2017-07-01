/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_SELECTIF_HH
#define AEIOU_HEADER_TYPETRAITS_SELECTIF_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<bool Condition_, typename True_, typename False_>
		class SelectIf AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(SelectIf)

		public:
			typedef True_ Type;
		};
		template<typename True_, typename False_>
		class SelectIf<false, True_, False_> AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(SelectIf)

		public:
			typedef False_ Type;
		};
	}
}

#endif
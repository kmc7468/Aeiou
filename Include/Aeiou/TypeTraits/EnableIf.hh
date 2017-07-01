/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_ENABLEIF_HH
#define AEIOU_HEADER_TYPETRAITS_ENABLEIF_HH
#include <Aeiou/Configurations.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<bool Condition_, typename Ty_ = void>
		class EnableIf AEIOU_FINAL
		{
			AEIOU_NON_INHERITABLE(EnableIf)

		public:
			typedef Ty_ Type;
		};
		template<typename Ty_>
		class EnableIf<false, Ty_> AEIOU_FINAL
		{
			AEIOU_NON_INHERITABLE(EnableIf)
		};
	}

	using TypeTraits::EnableIf;
}

#endif
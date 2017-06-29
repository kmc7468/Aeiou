/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_MAKEUNSIGNED_HH
#define AEIOU_HEADER_TYPETRAITS_MAKEUNSIGNED_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

#include "Details/ChangeSign.hh"

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class MakeUnsigned AEIOU_FINAL
		{
			AEIOU_NON_INHERITABLE(MakeUnsigned)

		public:
			typedef typename Details::ChangeSign_<Ty_>::Unsigned Type;
		};
	}

	using TypeTraits::MakeUnsigned;
}

#endif
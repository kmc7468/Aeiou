/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_REMOVECV_HH
#define AEIOU_HEADER_TYPETRAITS_REMOVECV_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		template<typename Ty_>
		class RemoveCV AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(RemoveCV)

		public:
			typedef Ty_ Type;
		};
		template<typename Ty_>
		class RemoveCV<const Ty_> AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(RemoveCV)

		public:
			typedef Ty_ Type;
		};
		template<typename Ty_>
		class RemoveCV<volatile Ty_> AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(RemoveCV)

		public:
			typedef Ty_ Type;
		};
		template<typename Ty_>
		class RemoveCV<const volatile Ty_> AEIOU_FINAL
			: Utilities::NonComparable, Utilities::NonCopyable
		{
			AEIOU_NON_INHERITABLE(RemoveCV)

		public:
			typedef Ty_ Type;
		};
	}

	using TypeTraits::RemoveCV;
}

#endif
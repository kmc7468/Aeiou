/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_CONSTANT_HH
#define AEIOU_HEADER_TYPETRAITS_CONSTANT_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Preprocessor/Features-Supported.hh>
#include <Aeiou/TypeTraits/EnableIf.hh>
#include <Aeiou/TypeTraits/RemoveCV.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		namespace Details
		{
			template<typename Left_, typename Right_>
			class IsEqual_ AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(IsEqual_)

			public:
				AEIOU_CONSTEXPR static const bool Value = false;
			};
			template<typename Ty_>
			class IsEqual_<Ty_, Ty_> AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(IsEqual_)

			public:
				AEIOU_CONSTEXPR static const bool Value = true;
			};

			template<typename Ty_>
			class IsInteger_ AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(IsInteger_)

			public:
				AEIOU_CONSTEXPR static const bool Value =
					IsEqual_<typename RemoveCV<Ty_>::Type, bool				>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, char				>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, signed char		>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, unsigned char	>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, wchar_t			>::Value ||
#ifdef AEIOU_SUPPORTED_NEW_CHAR
					IsEqual_<typename RemoveCV<Ty_>::Type, char16_t			>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, char32_t			>::Value ||
#endif
					IsEqual_<typename RemoveCV<Ty_>::Type, signed short		>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, unsigned short	>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, signed int		>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, unsigned int		>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, signed long		>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, unsigned long	>::Value
#ifdef AEIOU_SUPPORTED_LONGLONG
					||
					IsEqual_<typename RemoveCV<Ty_>::Type, signed long long	>::Value ||
					IsEqual_<typename RemoveCV<Ty_>::Type, unsigned long long>::Value
#endif
					;
			};
		}

#ifndef AEIOU_SUPPORTED_CONSTEXPR
		template<typename Ty_, Ty_ Value_>
		class Constant
			: Utilities::NonComparable, Utilities::NonCopyable
		{
		public:
			typedef Ty_ Type;

		public:
			AEIOU_CONSTEXPR static const Ty_ Value = Value_;
		};
#else
		template<typename Ty_, Ty_ Value_, typename = void>
		class Constant;

		template<typename Ty_, Ty_ Value_>
		class Constant<Ty_, Value_, typename EnableIf<Details::IsInteger_<Ty_>::Value>::Type>
			: Utilities::NonComparable, Utilities::NonCopyable
		{
		public:
			typedef Ty_ Type;

		public:
			static const Ty_ Value = Value_;
		};
		template<typename Ty_, Ty_ Value_>
		class Constant<Ty_, Value_, typename EnableIf<!Details::IsInteger_<Ty_>::Value>::Type>
			: Utilities::NonComparable, Utilities::NonCopyable
		{
		public:
			typedef Ty_ Type;

		public:
			static const Ty_ Value;
		};
		template<typename Ty_, Ty_ Value_>
		const Ty_ Constant<Ty_, Value_,
			typename EnableIf<!Details::IsInteger_<Ty_>::Value>::Type>::Value
			= Value_;
#endif

		typedef Constant<bool, true>	True_t;
		typedef Constant<bool, false>	False_t;
	}

	using TypeTraits::Constant;
	using TypeTraits::True_t;
	using TypeTraits::False_t;
}

#endif
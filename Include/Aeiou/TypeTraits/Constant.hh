/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_CONSTANT_HH
#define AEIOU_HEADER_TYPETRAITS_CONSTANT_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Preprocessor/Features-Supported.hh>
#include <Aeiou/TypeTraits/EnableIf.hh>
#include <Aeiou/TypeTraits/IsInteger.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
#ifdef AEIOU_SUPPORTED_CONSTEXPR
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
		class Constant<Ty_, Value_, typename EnableIf<IsInteger<Ty_>::Value>::Type>
			: Utilities::NonComparable, Utilities::NonCopyable
		{
		public:
			typedef Ty_ Type;

		public:
			static const Ty_ Value = Value_;
		};
		template<typename Ty_, Ty_ Value_>
			class Constant<Ty_, Value_, typename EnableIf<!IsInteger<Ty_>::Value>::Type>
			: Utilities::NonComparable, Utilities::NonCopyable
		{
		public:
			typedef Ty_ Type;

		public:
			static const Ty_ Value;
		};
		template<typename Ty_, Ty_ Value_>
		const Ty_ Constant<Ty_, Value_, typename EnableIf<!IsInteger<Ty_>::Value>::Type>::Value 
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
/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_NUMERICS_RATIO_HH
#define AEIOU_HEADER_NUMERICS_RATIO_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/TypeTraits/Constant.hh>
#include <Aeiou/Utilities/Integer.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace Numerics
	{
		template<Utilities::IntMax_t Numerator_, Utilities::IntMax_t Denominator_ = 1>
		class Ratio
			: Utilities::NonComparable, Utilities::NonCopyable
		{
		public:
			typedef Ratio<Numerator_, Denominator_> Type;

		public:
			AEIOU_CONSTEXPR static const Utilities::IntMax_t Numerator = Numerator_;
			AEIOU_CONSTEXPR static const Utilities::IntMax_t Denominator = Denominator_;
		};

#ifdef AEIOU_INTEGER_MAX_64
		typedef Ratio<1000000000000000000, 1> Exa;
		typedef Ratio<1000000000000000	 , 1> Peta;
		typedef Ratio<1000000000000		 , 1> Tera;
#endif
		typedef Ratio<1000000000		 , 1> Giga;
		typedef Ratio<1000000			 , 1> Mega;
		typedef Ratio<1000				 , 1> Killo;
		typedef Ratio<100				 , 1> Hecto;
		typedef Ratio<10				 , 1> Deca;

#ifdef AEIOU_INTEGER_MAX_64
		typedef Ratio<1, 1000000000000000000> Atto;
		typedef Ratio<1, 1000000000000000	> Femto;
		typedef Ratio<1, 1000000000000		> Pico;
#endif
		typedef Ratio<1, 1000000000			> Nano;
		typedef Ratio<1, 1000000			> Micro;
		typedef Ratio<1, 1000				> Milli;
		typedef Ratio<1, 100				> Centi;
		typedef Ratio<1, 10					> Deci;

		namespace Details
		{
			template<Utilities::IntMax_t Left_, Utilities::IntMax_t Right_>
			class Max_ AEIOU_FINAL
				: public TypeTraits::Constant<Utilities::IntMax_t,
				((Left_ > Right_) ? Left_ : Right_)>
			{
				AEIOU_NON_INHERITABLE(Max_)
			};

			template<Utilities::IntMax_t Left_, Utilities::IntMax_t Right_>
			class Min_ AEIOU_FINAL
				: public TypeTraits::Constant<Utilities::IntMax_t,
				((Left_ < Right_) ? Left_ : Right_)>
			{
				AEIOU_NON_INHERITABLE(Min_)
			};

			template<Utilities::IntMax_t Left_, Utilities::IntMax_t Right_>
			class Gcd_ AEIOU_FINAL
				: public TypeTraits::Constant<Utilities::IntMax_t,
				Gcd_<Min_<Left_, Right_>::Value,
				Max_<Left_, Right_>::Value % Min_<Left_, Right_>::Value>::Value>
			{
				AEIOU_NON_INHERITABLE(Gcd_)
			};
			template<Utilities::IntMax_t Left_>
			class Gcd_<Left_, 0> AEIOU_FINAL
				: public TypeTraits::Constant<Utilities::IntMax_t, Left_>
			{
				AEIOU_NON_INHERITABLE(Gcd_)
			};

			template<Utilities::IntMax_t Left_, Utilities::IntMax_t Right_>
			class Lcm_ AEIOU_FINAL
				: public TypeTraits::Constant<Utilities::IntMax_t,
				Left_ / Gcd_<Left_, Right_>::Value * Right_>
			{
				AEIOU_NON_INHERITABLE(Lcm_)
			};

			template<typename Ratio_>
			class Simplify_ AEIOU_FINAL
				: Utilities::NonComparable, Utilities::NonCopyable
			{
				AEIOU_NON_INHERITABLE(Simplify_)

			public:
				typedef Ratio<
					(Ratio_::Numerator / (Gcd_<Ratio_::Numerator, Ratio_::Denominator>::Value)),
					(Ratio_::Denominator / (Gcd_<Ratio_::Numerator, Ratio_::Denominator>::Value))
				> Type;
			};
			template<>
			class Simplify_<Ratio<0, 0>> AEIOU_FINAL
				: Utilities::NonComparable, Utilities::NonCopyable
			{
				AEIOU_NON_INHERITABLE(Simplify_)

			public:
				typedef Ratio<0, 0> Type;
			};
			template<Utilities::IntMax_t Numerator_>
			class Simplify_<Ratio<Numerator_, 0>> AEIOU_FINAL
				: Utilities::NonComparable, Utilities::NonCopyable
			{
				AEIOU_NON_INHERITABLE(Simplify_)

			public:
				typedef Ratio<0, 0> Type;
			};
			template<Utilities::IntMax_t Denominator_>
			class Simplify_<Ratio<0, Denominator_>> AEIOU_FINAL
				: Utilities::NonComparable, Utilities::NonCopyable
			{
				AEIOU_NON_INHERITABLE(Simplify_)

			public:
				typedef Ratio<0, 0> Type;
			};

			template<typename Left_, typename Right_>
			class Reduction_ AEIOU_FINAL
				: Utilities::NonComparable, Utilities::NonCopyable
			{
				AEIOU_NON_INHERITABLE(Reduction_)

			public:
				typedef Ratio<
					(Left_::Numerator * (Left_::Numerator /
					(Left_::Denominator * (Right_::Denominator / Details::Gcd_<
											Left_::Denominator, Right_::Denominator>::Value)))),
					(Left_::Denominator * (Right_::Denominator / Details::Gcd_<
											Left_::Denominator, Right_::Denominator>::Value))
				> TypeA;
				typedef Ratio<
					(Right_::Numerator * (Right_::Numerator /
					(Left_::Denominator * (Right_::Denominator / Details::Gcd_<
											Left_::Denominator, Right_::Denominator>::Value)))),
					(Left_::Denominator * (Right_::Denominator / Details::Gcd_<
											Left_::Denominator, Right_::Denominator>::Value))
				> TypeB;
			};
		}
	
		template<typename Left_, typename Right_>
		class RatioAdd
			: public Details::Simplify_<Ratio<
			(Left_::Numerator * (Right_::Denominator / Details::Gcd_<
								 Left_::Denominator, Right_::Denominator>::Value)) +
								(Right_::Numerator * (Left_::Denominator / Details::Gcd_<
								 Left_::Denominator, Right_::Denominator>::Value)),
								(Left_::Denominator * (Right_::Denominator / Details::Gcd_<
								 Left_::Denominator, Right_::Denominator>::Value))>>::Type
		{};

		template<typename Left_, typename Right_>
		class RatioSub
			: public Details::Simplify_<Ratio<
			(Left_::Numerator * (Right_::Denominator / Details::Gcd_<
								 Left_::Denominator, Right_::Denominator>::Value)) -
								(Right_::Numerator * (Left_::Denominator / Details::Gcd_<
								 Left_::Denominator, Right_::Denominator>::Value)),
								(Left_::Denominator * (Right_::Denominator / Details::Gcd_<
								 Left_::Denominator, Right_::Denominator>::Value))>>::Type
		{};

		template<typename Left_, typename Right_>
		class RatioMul
			: public Details::Simplify_<Ratio<Left_::Numerator * Right_::Numerator,
			Left_::Denominator * Right_::Denominator>>::Type
		{};

		template<typename Left_, typename Right_>
		class RatioDiv
			: public RatioMul<Left_, Ratio<Right_::Denominator, Right_::Numerator>>
		{};

		template<typename Left_, typename Right_>
		class RatioEqual AEIOU_FINAL
			: public TypeTraits::Constant<bool,
			(Details::Simplify_<Left_>::Type::Numerator ==
			 Details::Simplify_<Right_>::Type::Numerator) &&
			 (Details::Simplify_<Left_>::Type::Denominator ==
			  Details::Simplify_<Right_>::Type::Denominator)>
		{};

		template<typename Left_, typename Right_>
		class RatioNotEqual AEIOU_FINAL
			: public TypeTraits::Constant<bool,
			!((Details::Simplify_<Left_>::Type::Numerator ==
			 Details::Simplify_<Right_>::Type::Numerator) &&
			 (Details::Simplify_<Left_>::Type::Denominator ==
			  Details::Simplify_<Right_>::Type::Denominator))>
		{};

		template<typename Left_, typename Right_>
		class RatioLess
			: public TypeTraits::Constant<bool,
			(Details::Reduction_<Left_, Right_>::TypeA::Numerator <
			 Details::Reduction_<Left_, Right_>::TypeB::Numerator)>
		{};

		template<typename Left_, typename Right_>
		class RatioLessEqual
			: public TypeTraits::Constant<bool,
			(Details::Reduction_<Left_, Right_>::TypeA::Numerator <=
			 Details::Reduction_<Left_, Right_>::TypeB::Numerator)>
		{};

		template<typename Left_, typename Right_>
		class RatioGreater
			: public TypeTraits::Constant<bool,
			(Details::Reduction_<Left_, Right_>::TypeA::Numerator >
			 Details::Reduction_<Left_, Right_>::TypeB::Numerator)>
		{};

		template<typename Left_, typename Right_>
		class RatioGreaterEqual
			: public TypeTraits::Constant<bool,
			(Details::Reduction_<Left_, Right_>::TypeA::Numerator >=
			 Details::Reduction_<Left_, Right_>::TypeB::Numerator)>
		{};
	}

	using Numerics::Ratio;

#ifdef AEIOU_INTEGER_MAX_64
	using Numerics::Exa;
	using Numerics::Peta;
	using Numerics::Tera;
#endif
	using Numerics::Giga;
	using Numerics::Mega;
	using Numerics::Killo;
	using Numerics::Hecto;
	using Numerics::Deca;

#ifdef AEIOU_INTEGER_MAX_64
	using Numerics::Atto;
	using Numerics::Femto;
	using Numerics::Pico;
#endif
	using Numerics::Nano;
	using Numerics::Micro;
	using Numerics::Milli;
	using Numerics::Centi;
	using Numerics::Deci;

	using Numerics::RatioAdd;
	using Numerics::RatioSub;
	using Numerics::RatioMul;
	using Numerics::RatioDiv;

	using Numerics::RatioEqual;
	using Numerics::RatioNotEqual;

	using Numerics::RatioLess;
	using Numerics::RatioLessEqual;
	using Numerics::RatioGreater;
	using Numerics::RatioGreaterEqual;
}

#endif
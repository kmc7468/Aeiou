/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_NUMERICS_RATIO_HH
#define AEIOU_HEADER_NUMERICS_RATIO_HH
#include <Aeiou/Configurations.hh>

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
	}
}

#endif
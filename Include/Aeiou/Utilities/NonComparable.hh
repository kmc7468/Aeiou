/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_UTILITIES_NONCOMPARABLE_HH
#define AEIOU_HEADER_UTILITIES_NONCOMPARABLE_HH

#include <Aeiou/Preprocessor/Features-Supported.hh>

namespace Aeiou
{
	namespace Utilities
	{
		class NonComparable
		{
		protected:
			~NonComparable()
			{}

#ifdef AEIOU_SUPPORTED_DELETE
		public:
			bool operator==(const NonComparable& instance) const AEIOU_NOEXCEPT = delete;
			bool operator!=(const NonComparable& instance) const AEIOU_NOEXCEPT = delete;
#else
		private:
			bool operator==(const NonComparable& instance) const AEIOU_NOEXCEPT;
			bool operator!=(const NonComparable& instance) const AEIOU_NOEXCEPT;
#endif
		};
	}

	using Utilities::NonComparable;
}

#endif
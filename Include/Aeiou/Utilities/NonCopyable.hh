/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_UTILITIES_NONCOPYABLE_HH
#define AEIOU_HEADER_UTILITIES_NONCOPYABLE_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Preprocessor/Features-Supported.hh>

namespace Aeiou
{
	namespace Utilities
	{
		class NonCopyable
		{
#ifdef AEIOU_SUPPORTED_DELETE
		public:
			NonCopyable(const NonCopyable& instance) = delete;
#endif

		protected:
			AEIOU_CONSTEXPR NonCopyable()
			{}
			~NonCopyable()
			{}

#ifndef AEIOU_SUPPORTED_DELETE
		private:
			NonCopyable(const NonCopyable& instance);
#endif

#ifdef AEIOU_SUPPORTED_DELETE
		public:
			NonCopyable& operator=(const NonCopyable& instance) = delete;
#else
		private:
			NonCopyable& operator=(const NonCopyable& instance);
#endif
		};
	}

	using Utilities::NonCopyable;
}

#endif
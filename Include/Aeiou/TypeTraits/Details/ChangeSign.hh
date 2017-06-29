/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_TYPETRAITS_DETAILS_CHANGESIGN_HH
#define AEIOU_HEADER_TYPETRAITS_DETAILS_CHANGESIGN_HH
#include <Aeiou/Configurations.hh>

#include <Aeiou/Preprocessor/Features-Supported.hh>
#include <Aeiou/TypeTraits/IsEqual.hh>
#include <Aeiou/Utilities/NonComparable.hh>
#include <Aeiou/Utilities/NonCopyable.hh>

namespace Aeiou
{
	namespace TypeTraits
	{
		namespace Details
		{
			template<bool Condition_, typename True_, typename False_>
			class If_ AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(If_)

			public:
				typedef True_ Type;
			};
			template<typename True_, typename False_>
			class If_<false, True_, False_> AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(If_)

			public:
				typedef False_ Type;
			};

			template<typename Ty_>
			class ChangeSign_ AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(ChangeSign_)

			public:
				typedef
					typename If_<
					IsEqual<Ty_, char>::Value || IsEqual<Ty_, signed char>::Value ||
					IsEqual<Ty_, unsigned char>::Value, signed char,
					typename If_<
					IsEqual<Ty_, short>::Value || IsEqual<Ty_, unsigned short>::Value,
					short,
					typename If_<
					IsEqual<Ty_, int>::Value || IsEqual<Ty_, unsigned int>::Value,
					int,
					typename If_<
					IsEqual<Ty_, long>::Value || IsEqual<Ty_, unsigned long>::Value,
					long,
#ifdef AEIOU_SUPPORTED_LONGLONG
					typename If_<
					IsEqual<Ty_, long long>::Value || IsEqual<Ty_, unsigned long long>::Value,
					long long,
#endif
					Ty_>::Type>::Type>::Type>::Type
#ifdef AEIOU_SUPPORTED_LONGLONG
					>::Type
#endif
					Signed;
				typedef
					typename If_<
					IsEqual<Ty_, char>::Value || IsEqual<Ty_, signed char>::Value ||
					IsEqual<Ty_, unsigned char>::Value, unsigned char,
					typename If_<
					IsEqual<Ty_, short>::Value || IsEqual<Ty_, unsigned short>::Value,
					unsigned short,
					typename If_<
					IsEqual<Ty_, int>::Value || IsEqual<Ty_, unsigned int>::Value,
					unsigned int,
					typename If_<
					IsEqual<Ty_, long>::Value || IsEqual<Ty_, unsigned long>::Value,
					unsigned long,
#ifdef AEIOU_SUPPORTED_LONGLONG
					typename If_<
					IsEqual<Ty_, long long>::Value || IsEqual<Ty_, unsigned long long>::Value,
					unsigned long long,
#endif
					Ty_>::Type>::Type>::Type>::Type
#ifdef AEIOU_SUPPORTED_LONGLONG
					>::Type
#endif
					Unsigned;
			};
			template<typename Ty_>
			class ChangeSign_<const Ty_> AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(ChangeSign_)

			public:
				typedef const typename ChangeSign_<Ty_>::Signed Signed;
				typedef const typename ChangeSign_<Ty_>::Unsigned Unsigned;
			};
			template<typename Ty_>
			class ChangeSign_<volatile Ty_> AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(ChangeSign_)

			public:
				typedef volatile typename ChangeSign_<Ty_>::Signed Signed;
				typedef volatile typename ChangeSign_<Ty_>::Unsigned Unsigned;
			};
			template<typename Ty_>
			class ChangeSign_<const volatile Ty_> AEIOU_FINAL
			{
				AEIOU_NON_INHERITABLE(ChangeSign_)

			public:
				typedef const volatile typename ChangeSign_<Ty_>::Signed Signed;
				typedef const volatile typename ChangeSign_<Ty_>::Unsigned Unsigned;
			};
		}
	}
}

#endif
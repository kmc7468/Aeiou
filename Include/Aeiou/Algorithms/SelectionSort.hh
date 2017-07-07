/*
Aeiou is protected by Aeiou Public License Version 1.
Made by kmc7468
*/

#ifndef AEIOU_HEADER_ALGORITHMS_SELECTIONSORT_HH
#define AEIOU_HEADER_ALGORITHMS_SELECTIONSORT_HH

namespace Aeiou
{
	namespace Algorithms
	{
		template<typename Iterator_>
		void SelectionSort(Iterator_ begin, Iterator_ end);
	}
}

#include "Details/SelectionSort.hh"
#endif
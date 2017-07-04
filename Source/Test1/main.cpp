#include <Aeiou/Aeiou.hh>

#include <iostream>

int main()
{
	typedef Aeiou::Ratio<3, 5> a;
	typedef Aeiou::Ratio<3, 5> b;

	typedef Aeiou::RatioDiv<a, b>::Type c;

	std::cout << c::Numerator << '/' << c::Denominator << std::endl;

	return 0;
}
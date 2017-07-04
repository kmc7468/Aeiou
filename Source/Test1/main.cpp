#include <Aeiou/Aeiou.hh>

#include <iostream>

int main()
{
	typedef Aeiou::Ratio<3, 5> left;
	typedef Aeiou::Ratio<3, 5> right;

	typedef Aeiou::RatioAdd<left, right> add;
	typedef Aeiou::RatioSub<left, right> sub;
	typedef Aeiou::RatioMul<left, right> mul;
	typedef Aeiou::RatioDiv<left, right> div;

	typedef Aeiou::RatioLess<left, right> less;
	typedef Aeiou::RatioLessEqual<left, right> less_equal;
	typedef Aeiou::RatioGreater<left, right> greater;
	typedef Aeiou::RatioGreaterEqual<left, right> greater_equal;

	typedef Aeiou::RatioEqual<left, right> equal;
	typedef Aeiou::RatioNotEqual<left, right> not_equal;

	std::cout << left::Numerator << '/' << left::Denominator << " + " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		add::Numerator << '/' << add::Denominator << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " - " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		sub::Numerator << '/' << sub::Denominator << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " * " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		mul::Numerator << '/' << mul::Denominator << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " / " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		div::Numerator << '/' << div::Denominator << '\n';

	std::cout << std::boolalpha;
	std::cout << left::Numerator << '/' << left::Denominator << " > " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		less::Value << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " >= " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		less_equal::Value << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " < " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		greater::Value << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " <= " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		greater_equal::Value << '\n';

	std::cout << left::Numerator << '/' << left::Denominator << " == " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		equal::Value << '\n';
	std::cout << left::Numerator << '/' << left::Denominator << " != " <<
		right::Numerator << '/' << right::Denominator << " = " <<
		not_equal::Value << '\n';

	return 0;
}
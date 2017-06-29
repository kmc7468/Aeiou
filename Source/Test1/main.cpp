#include <Aeiou/Aeiou.hh>

#include <iostream>

int main()
{
	std::cout.sync_with_stdio(false);
	std::cout << std::boolalpha;

	std::cout << Aeiou::IsEqual<int, int>::Value << std::endl;
	std::cout << Aeiou::IsEqual<int, double>::Value << std::endl;

	return 0;
}
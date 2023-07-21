#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> a(6);
	Array<char> b(6);

	for (size_t i = 0; i < a.size(); i++)
		a[i] = 24 + i;

	for (size_t i = 0; i < b.size(); i++)
		b[i] = 65 + i;
		
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	return (0);
}
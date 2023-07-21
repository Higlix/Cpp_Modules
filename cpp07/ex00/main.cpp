#include "whatever.hpp"

int main(int /*argc*/, char** /*argv*/)
{
	int a = 5;
	int b = 8;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl << std::endl;

	swap(a, b);
	// or 'swap<int>(a, b);'

	std::cout << "after swap<int>(a, b)" << std::endl << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl << std::endl;

	std::cout << "min(a, b) = " << min(a, b) << std::endl; // min<int>(a, b)
	std::cout << "max(a, b) = " << max(a, b) << std::endl; // max<int>(a, b)

	return (0);
}
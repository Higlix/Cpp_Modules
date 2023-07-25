#include "easyfind.hpp"

int main(int, char**)
{
	std::vector<int> a;

	for (int i = 0; i < 5; i++)
		a.push_back(i + 1);

	try {
		::easyfind(a, 2);
	} catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
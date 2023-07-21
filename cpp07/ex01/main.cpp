#include "iter.hpp"

void	chChar(char *chr)
{
	(*chr) += 1;
}

void	chInt(int *nbr)
{
	(*nbr) += 1;
}

int main(int, char**)
{
	{
		int arr[] = {1, 2, 3, 4, 5};

		std::cout << "int array[];\n before iter<int>()\n" << std::endl;

		std::cout << "BEFORE" << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n\n";

		std::cout << "AFTER" << std::endl;
		iter<int>(arr, 5, &chInt);

		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	std::cout << "==============================" << std::endl;
	{
		char arr[] = "ABCDEF";
		std::cout << "char array[];\n before iter<char>()\n" << std::endl;

		std::cout << "BEFORE" << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n\n";

		std::cout << "AFTER" << std::endl;
		iter<char>(arr, 5, &chChar);

		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

	}

	return (0);
}
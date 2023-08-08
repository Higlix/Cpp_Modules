#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (!(argc > 3))
	{
		std::cout << "Need More Numbers" << std::endl;
		return (-1);
	}

	PmergeMe merge(argc, argv);

	merge.giveInfo();
	merge.mergeDeque();
	merge.mergeVector();


	return (0);
}
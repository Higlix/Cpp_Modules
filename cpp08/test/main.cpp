#include <iostream>
#include <array>
#include <vector>
#include <iterator>

int main(void)
{
	std::vector<int> a;

	for (int i = 0; i < 12; i++)
		a.push_back(i + 1);

	std::vector<int>::iterator start;
	std::vector<int>::iterator end;

	start = a.begin();

	end = a.end();

	int valueToFind = 9;

	while (start != end)
	{
		if (*start == valueToFind)
			std::cout << "Value Was Found" << std::endl;

		start++;
	}

	return (0);
}
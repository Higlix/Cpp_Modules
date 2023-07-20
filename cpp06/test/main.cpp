#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

int main(void)
{
	float f = 23.4424;

	int b = static_cast<int>(f);

	std::string nbr = "4.345";

	char ba[] = "3.424";

	float n = atof(ba);
	int	n1 = atoi(ba);

	std::cout << ba << std::endl;
	std::cout << n << std::endl;
	std::cout << n1 << std::endl;
}
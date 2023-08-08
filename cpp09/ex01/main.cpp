#include "RPN.hpp"

void	usageError()
{
	std::cerr << "Usage Error: ./RPN \"7 7 * 7 -\"" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			std::cout << RPN::calculate(argv[1]) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		usageError();

	return (0);	
}
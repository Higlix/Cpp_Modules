#include <iostream>
#include "Bureaucrat.hpp"

int main(int /*argc*/, char **/*argv*/)
{
	try
	{
		Bureaucrat	james("James", 24);
		Form		bizDeal("Deal", 23, 24);
		
		james.signForm(bizDeal);
	} 
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
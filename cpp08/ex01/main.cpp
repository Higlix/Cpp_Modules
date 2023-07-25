#include "Span.hpp"

int main(int, char **)
{
	try
	{
		Span a(4);

		a.addNumber(23);
		a.addNumber(44);
		a.addNumber(2);
		a.addNumber(33);

		int shortestSpan = a.shortestSpan();
		int longestSpan = a.longestSpan();

		std::cout << "a shortestSpan --> ( " << shortestSpan << " )" << std::endl;
		std::cout << "a longestSpan --> ( " << longestSpan << " )" << std::endl;
	
		Span b(5);

		b.addNumber(24);

		b.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
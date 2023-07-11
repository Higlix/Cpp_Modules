// // #include "Bureaucrat.hpp"
// #include <stdexcept>


// int main(int /*argc*/, char **/*argv*/)
// {
// 	std::exception a;

//     return (0);
// }

// #include <iostream>

// class MyClass {
// public:
//     MyClass(int value);
// };

// MyClass createObject() {
// 	return (MyClass(42));
// }

// int main() {
//     MyClass newObj = createObject();
//     return 0;
// }

#include <iostream>


class Exe : public std::exception
{
	public:
		const char* what() const throw()  {
			return ("ZERO_DIV ERROR #334eb");
		}
};

std::string		doDiv(int n1, int n2)
{
	if (n2 == 0)
		throw(Exe());

	int calcu = n1 / n2;

	std::cout << calcu;

	std::string res = "->";
	return (res);
}

void	foo()
{
	std::cout << doDiv(1, 45) << std::endl;
	std::cout << doDiv(45, 1) << std::endl;
	std::cout << doDiv(5, 0) << std::endl;


	std::cout << "foo done" << std::endl;
}

void	bar()
{
	std::cout << doDiv(5, 1) << std::endl;


	std::cout << "foo done" << std::endl;
}


int main(void)
{
	try
	{
		foo();

	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
		bar();
	}

	return (0);
}
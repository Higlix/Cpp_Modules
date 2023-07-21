#include <iostream>

template <typename T>
T add(T num1, T num2) {
   return (num1 + num2);
}

int main(void)
{

	std::cout << "add<int> --> ";
	std::cout << add<int>(4, 4) << std::endl;


	std::cout << "add<float> --> ";
	std::cout << add<float>(4.4f, 4.4f) << std::endl;


	return (0);
}
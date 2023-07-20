#include "Serializer.hpp"

int main(void)
{
	Data *kedi = new Data;

	std::cout << "Data has been created" << std::endl << std::endl;
	std::cout << "Data kedi;" << std::endl;
	std::cout << "kedi contains -> \" ";
	std::cout << kedi->getName() << " \"" << std::endl;

	std::cout << "\n";

	uintptr_t seria_ptr = Serializer::serialize(kedi);

	std::cout << "After serialize() call" << std::endl;
	std::cout << "Return value = ' " << seria_ptr << " '" << std::endl;
	std::cout << "\n\n";
	std::cout << "Creating new pointer 'idek'" << std::endl << std::endl;

	Data *idek;

	std::cout << "Called deserialize() on idek with serialize(kedi) return value" << std::endl;
	std::cout << "\n";

	idek = Serializer::deserialize(seria_ptr);

	std::cout << "If 'idek' is equal to 'kedi' the program will write 'true' now" << std::endl;
	
	if (idek == kedi)
		std::cout << "TRUE" << std::endl;
	else 
		std::cout << "FALSE" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Lastly calling idek->getName(): ";
	std::cout << "' " << idek->getName() << " '" << std::endl;

	delete kedi;
	return (0);
}
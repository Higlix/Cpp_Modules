#include "PhoneBook.hpp"
#include <unistd.h>

int main(void)
{
	PhoneBook pb;
	int input_val;

	greet_user();
	pb.contact_count = 0;
	while (1)
	{
		show_options();
		input_val = take_input();
		if (input_val == -1)
		{
			std::cout << "*** INPUT ERROR ***" << std::endl;
			continue ;
		}
		if (input_val == 1)
			pb.add_user();
		else if (input_val == 2)
			pb.show_user();
		else if (input_val == 3)
			break ;
	}
	std::cout << "THANK YOU FOR USING THE PHONEBOOK :)" << std::endl;
	return (0);
}
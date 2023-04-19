#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"

class PhoneBook {
	public:
		int contact_count;
		Contact contacts[8];
		void	add_user();
		void	show_user();
};

int		take_input();

void	greet_user();
void	show_options();

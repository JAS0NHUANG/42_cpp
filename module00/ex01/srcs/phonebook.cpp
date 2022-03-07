#include "main.hpp"


PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::print_all_contact(void)
{
	std::cout << std::setw(10) << "index" \
		<< " | " << std::setw(10) << "First name" \
		<< " | " << std::setw(10) << "Last name" \
		<< " | " << std::setw(10) << "Nickname" \
		<< "\n";
	for (int index = 0; index < 9; index++)
	{
		if (this->the_phonebook[index].first_name == "")
			break ;
		std::cout << std::setw(10) << index \
			<< " | " << std::setw(10) << this->the_phonebook[index].first_name \
			<< " | " << std::setw(10) << this->the_phonebook[index].last_name \
			<< " | " << std::setw(10) << this->the_phonebook[index].nickname \
			<< "\n";
	}
	return ;
}

void	PhoneBook::print_contact(int index)
{
	if (index > 8 || this->the_phonebook[index].first_name == "")
		return ;
	std::cout << std::setw(10) << index \
		<< " | " << std::setw(10) << this->the_phonebook[index].first_name \
		<< " | " << std::setw(10) << this->the_phonebook[index].last_name \
		<< " | " << std::setw(10) << this->the_phonebook[index].nickname \
		<< "\n";
	return ;
}

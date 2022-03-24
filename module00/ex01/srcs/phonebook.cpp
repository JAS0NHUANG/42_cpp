#include "main.hpp"

PhoneBook::PhoneBook(void){}

PhoneBook::~PhoneBook(void){}

int	PhoneBook::is_contact_empty(int index) {
	return (this->contacts_array[index].get_first_name() == "");
}

void	PhoneBook::add_contact(int index, Contact new_contact) {
	this->contacts_array[index] = new_contact;
}

void	PhoneBook::print_all_contact(void) {
	if (this->contacts_array[0].get_first_name() == "")
		return ;
	std::cout << std::setw(10) << "index" \
		<< " | " << std::setw(10) << "First name" \
		<< " | " << std::setw(10) << "Last name" \
		<< " | " << std::setw(10) << "Nickname" \
		<< "\n";
	for (int index = 0; index < 8; index++) {
		if (this->contacts_array[index].get_first_name() == "")
			break ;
		std::cout << std::setw(10) << index \
			<< " | " << std::setw(10) << this->contacts_array[index].get_first_name() \
			<< " | " << std::setw(10) << this->contacts_array[index].get_last_name() \
			<< " | " << std::setw(10) << this->contacts_array[index].get_nickname() \
			<< "\n";
	}
	return ;
}

void	PhoneBook::print_contact(int index) {
	if (index > 7 || this->contacts_array[index].get_first_name() == "")
		return ;
	std::cout << std::setw(10) << "index" \
		<< " | " << std::setw(10) << "First name" \
		<< " | " << std::setw(10) << "Last name" \
		<< " | " << std::setw(10) << "Nickname" \
		<< " | " << std::setw(10) << "Darkest secret" \
		<< "\n";
	std::cout << std::setw(10) << index \
		<< " | " << std::setw(10) << this->contacts_array[index].get_first_name() \
		<< " | " << std::setw(10) << this->contacts_array[index].get_last_name() \
		<< " | " << std::setw(10) << this->contacts_array[index].get_nickname() \
		<< " | " << std::setw(10) << this->contacts_array[index].get_secret() \
		<< "\n";
	return ;
}

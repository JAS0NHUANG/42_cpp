#include "main.hpp"

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::print_all_contact(void)
{
	if (this->the_phonebook[0].first_name == "")
	{
		return ;
	}
	cout << setw(10) << "index" \
		<< " | " << setw(10) << "First name" \
		<< " | " << setw(10) << "Last name" \
		<< " | " << setw(10) << "Nickname" \
		<< "\n";
	for (int index = 0; index < 9; index++)
	{
		if (this->the_phonebook[index].first_name == "")
		{
			break ;
		}
		cout << setw(10) << index \
			<< " | " << setw(10) << this->the_phonebook[index].first_name \
			<< " | " << setw(10) << this->the_phonebook[index].last_name \
			<< " | " << setw(10) << this->the_phonebook[index].nickname \
			<< "\n";
	}
	return ;
}

void	PhoneBook::print_contact(int index)
{
	if (index > 8 || this->the_phonebook[index].first_name == "")
		return ;
	cout << setw(10) << index \
		<< " | " << setw(10) << this->the_phonebook[index].first_name \
		<< " | " << setw(10) << this->the_phonebook[index].last_name \
		<< " | " << setw(10) << this->the_phonebook[index].nickname \
		<< "\n";
	return ;
}

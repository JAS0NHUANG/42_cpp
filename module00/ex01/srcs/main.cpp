#include "main.hpp"

int to_int(std::string str) {
     int	index = 0;
	 int	result = 0;
	 int	negative = 1;

	 if (str[index] == '-')
		 negative = -1;
     if ( str[index] == '+' || str[index] == '-' )
         index++;
     if (!str[index])
	     return (INT_MIN);
     while(str[index]) {
          if ( str[index] < '0' || str[index] > '9' )
			  return (INT_MIN);
          result = result * 10  + (str[index] - '0');
          index++;
     }
     return (result * negative);
}

int	phonebook_search(PhoneBook my_phonebook) {
	int			search_index = -1;
	std::string	input = "";
	if (my_phonebook.is_contact_empty(0))
		std::cout << "The phone book is empty.\n";
	else {
		my_phonebook.print_all_contact();
		std::cout << "Enter The index of the contact you want to search:";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		if (input.empty())
			return (0);
		search_index = to_int(input);
		if (search_index < 0 || search_index > 7)
			std::cout << "Invalid index\n";
		else if (my_phonebook.is_contact_empty(search_index))
			std::cout << "Contact index " << search_index << " not found.\n";
		else
			my_phonebook.print_contact(search_index);
	}
	return (0);
}

int	main(void) {
	PhoneBook	my_phonebook;
	std::string	input = "";
	int			index = 0;

	while (input != "EXIT") {
		std::cout << "PhoneBook(ADD, SEARCH, or EXIT):";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else if (input == "ADD") {
			if (index == 8)
				index = 0;
			Contact new_contact;
			if (new_contact.create_new_contact() == 1)
				break ;
			my_phonebook.add_contact(index, new_contact);
			index++;
		}
		else if (input == "SEARCH") {
			if (phonebook_search(my_phonebook) == 1)
				break ;
		}
	}
	std::cout << "\nEXIT\n";
	return (0);
}

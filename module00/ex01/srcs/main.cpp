#include "main.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	PhoneBook	my_phonebook;
	int			index;
	std::string	input;

	std::cout << "PhoneBook(Available commands: ADD, SEARCH, or EXIT):";
	std::cin >> input;
	index = 0;
	while (input != "EXIT")
	{
		if (input == "ADD")
		{
			input = "";
			if (index == 9)
				index = 0;
			std::cout << "Enter your first name:";
			std::getline(std::cin,input);
			if (!input.empty())
				my_phonebook.the_phonebook[index].first_name = input;
			else
			{
				while (input.empty() || std::cin.eof() == true)
				{
					std::cin.clear();
					std::cout << "This field can not be empty:";
					std::getline(std::cin,input);
				}
			}
			std::cout << "Enter your last name:";
			std::getline(std::cin,input);
			if (!input.empty())
				my_phonebook.the_phonebook[index].last_name = input;
			else
			{
				while (input.empty())
				{
					std::cout << "This field can not be empty:";
					std::getline(std::cin,input);
				}
			}
			std::cout << "Enter your nickname:";
			std::cin >> input;
			while (input.empty())
			{
				std::cout << "This field can not be empty:";
				std::cin >> input;
			}
			my_phonebook.the_phonebook[index].nickname = input;
			std::cout << "Enter your darkest secret:";
			std::cin >> input;
			while (input.empty())
			{
				std::cout << "This field can not be empty:";
				std::cin >> input;
			}
			my_phonebook.the_phonebook[index].darkest_secret = input;
			std::cout << "\n";
			index++;
		}
		if (input == "SEARCH")
		{
			my_phonebook.print_all_contact();
			std::cout << "The index of the contact you want to search:";
			std::cin >> input;
			try
			{
				index = std::stoi(input);
				my_phonebook.print_contact(std::stoi(input));
			}
			catch(...)
			{
			}
		}

		std::cout << "PhoneBook(Available commands: ADD, SEARCH, or EXIT):";
		std::cin >> input;
	}
	return (0);
}

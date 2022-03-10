#include "main.hpp"

int to_int(string str)
{
     int index;
     index = 0;
     if (str[0] == '\0' )
        throw std::invalid_argument("null or empty string argument");

     bool negate = (str[0] == '-');
     if ( str[0] == '+' || str[0] == '-' ) 
         index++;

     if ( str[index] == '\0')
	 return (0);

     int result = 0;
     while(str[index])
     {
          if ( str[index] < '0' || str[index] > '9' )
		 return (0);
          result = result * 10  - (str[index] - '0');  //assume negative number
          index++;
     }
     return negate ? result : -result; //-result is positive!
}


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	PhoneBook	my_phonebook;
	int			index;
	int get_input;
	std::string	input;

	std::cout << "PhoneBook(Available commands: ADD, SEARCH, or EXIT):";
	while (1)
	{
		std::cin.clear();
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::cout << "OK\n";
			continue ;
		}
		else
		{
			std::cout << "NG\n";
			continue ;
		}
	}
	while (std::cin.fail() || std::cin.eof() || input.empty())
	{
		std::cout << "Command can't be empty\n";
		std::cout << "PhoneBook(Available commands: ADD, SEARCH, or EXIT):";
		std::getline(std::cin, input);
	}
	index = 0;
	while (input != "EXIT")
	{
		if (input == "ADD")
		{
			input.clear();
			if (index == 9)
				index = 0;
			std::cout << "Enter your first name:";
			std::cin >> input;
			while (input.empty() || std::cin.eof())
			{
				std::cin.clear();
				std::cout << "This field can not be empty:";
				std::cin >> input;
			}
			my_phonebook.the_phonebook[index].first_name = input;
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
			my_phonebook.print_all_contact();
			index++;
		}
		if (input == "SEARCH")
		{
			my_phonebook.print_all_contact();
			std::cout << "The index of the contact you want to search:";
			std::cin >> input;
			try
			{
				index = to_int(input);
				my_phonebook.print_contact(to_int(input));
			}
			catch(...)
			{
			}
		}

		std::cout << "PhoneBook(Available commands: ADD, SEARCH, or EXIT):";
		std::cin >> input;
		if (std::cin.eof() || input.empty())
			return (1);
	}
	return (0);
}

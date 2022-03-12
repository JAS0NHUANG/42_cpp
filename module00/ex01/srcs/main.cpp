#include "main.hpp"

int to_int(string str)
{
     int	index = 0;
	 int	result = 0;
	 int	negative = 1;

	 if (str[index] == '-')
		 negative = -1;
     if ( str[index] == '+' || str[index] == '-' )
         index++;
     while(str[index])
     {
          if ( str[index] < '0' || str[index] > '9' )
			  return (INT_MIN);
          result = result * 10  + (str[index] - '0');
          index++;
     }
     return (result * negative);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	PhoneBook	my_phonebook;
	int			search_index = -1;
	string		input = "";
	int			index = 0;

	while (input != "EXIT")
	{
		cout << "PhoneBook(Available commands: ADD, SEARCH, or EXIT):";
		getline(cin, input);
		if (cin.eof())
			break ;
		else if (input == "ADD")
		{
			if (index == 8)
				index = 0;
			Contact new_contact;
			if (new_contact.create_new_contact() == 1)
				break ;
			my_phonebook.add_contact(index, new_contact);
			index++;
		}
		else if (input == "SEARCH")
		{
			if (my_phonebook.is_contact_empty(0))
				cout << "The phone book is empty.\n";
			else
			{
				my_phonebook.print_all_contact();
				cout << "Enter The index of the contact you want to search:";
				getline(cin, input);
				if (cin.eof())
					break ;
				if (input.empty())
					continue ;
				search_index = to_int(input);
				if (search_index < 0 || search_index > 8)
					cout << "Invalid index\n";
				else if (my_phonebook.is_contact_empty(search_index))
					cout << "Contact index " << search_index << " not found.\n";
				else
					my_phonebook.print_contact(search_index);
			}
		}
	}
	cout << "\nEXIT\n";
	return (0);
}

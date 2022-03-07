#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <array>

using namespace std;

class	Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
};

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		std::array	<Contact, 9> the_phonebook;

		void		print_contact(int index);
		void		print_all_contact(void);
};

#endif

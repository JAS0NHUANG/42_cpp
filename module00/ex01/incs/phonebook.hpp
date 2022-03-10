#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(void);	
		void	print_all_contact(void);
		void	print_contact(int index);

	private:
		Contact	contacts_array[9];
};

#endif

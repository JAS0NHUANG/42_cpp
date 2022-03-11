#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add_contact(int index, Contact new_contact);
		void	print_all_contact(void);
		void	print_contact(int index);
		int		is_contact_empty(int index);

	private:
		Contact	contacts_array[9];
};

#endif

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact {
	public:
		Contact(void);
		~Contact(void);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_secret(void) const;
		void		set_first_name(std::string first_name);
		void		set_last_name(std::string last_name);
		void		set_nickname(std::string nickname);
		void		set_secret(std::string secret);
		int			create_new_contact(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	secret;
};

#endif

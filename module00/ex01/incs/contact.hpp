#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	public:
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string secret);
		~Contact(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_darkest_secret(void);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
};

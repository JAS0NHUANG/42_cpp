#include "main.hpp"

std::string	get_user_input(std::string const message) {
	std::string	user_input;
	std::cout << message;
	std::getline(std::cin, user_input);
	if (std::cin.eof())
		return "";
	while (user_input.empty()) {
		std::cout << "This field can not be empty:";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
			return "";
	}
	return (user_input);
}

Contact::Contact(void) {}

Contact::~Contact(void) {}

void	Contact::set_first_name(std::string first_name) {
	this->first_name = first_name;
}

void	Contact::set_last_name(std::string last_name) {
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}

void	Contact::set_secret(std::string secret) {
	this->secret= secret;
}

std::string	Contact::get_first_name(void) const {
	return (this->first_name);
}

std::string	Contact::get_last_name(void) const {
	return (this->last_name);
}

std::string	Contact::get_nickname(void) const {
	return (this->nickname);
}

std::string	Contact::get_secret(void) const {
	return (this->secret);
}

int	Contact::create_new_contact(void) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	secret;

	first_name = get_user_input("Enter your first name:");
	if (first_name.empty())
		return (1);
	last_name = get_user_input("Enter your last name:");
	if (last_name.empty())
		return (1);
	nickname = get_user_input("Enter your nickname:");
	if (nickname.empty())
		return (1);
	secret = get_user_input("Enter your darkest secret:");
	if (secret.empty())
		return (1);
	set_first_name(first_name);
	set_last_name(last_name);
	set_nickname(nickname);
	set_secret(secret);
	return (0);
}

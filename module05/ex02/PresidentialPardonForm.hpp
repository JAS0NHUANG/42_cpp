#ifndef PPF_HPP_
#define PPF_HPP_

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		// canonical
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &toCopy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &toAssign);
		PresidentialPardonForm(std::string target);

		// accessor
		const std::string &getTarget(void) const;

		// member functions
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};

#endif

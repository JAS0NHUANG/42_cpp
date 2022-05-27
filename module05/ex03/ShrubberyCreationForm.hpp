#ifndef SCF_HPP_
#define SCF_HPP_

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		// canonical
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &toAssign);
		ShrubberyCreationForm(std::string target);

		// accessor
		const std::string &getTarget(void) const;

		// member functions
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};

#endif

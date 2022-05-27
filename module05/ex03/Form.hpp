#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
	public:
		// canonical
		AForm(void);
		~AForm(void);
		AForm(const AForm &toCopy);
		AForm &operator=(const AForm &toAssign);
		AForm(std::string name, unsigned int signGrade, unsigned int execGrade);

		// accessor
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		unsigned int	getSignGrade(void) const;
		unsigned int	getExecGrade(void) const;

		void	setIsSigned(bool isSigned);

		// exception hendling
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormUnsignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// member functions
		void	beSigned(const Bureaucrat &b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
};

std::ostream	&operator<<(std::ostream& out, const AForm& f);

#endif

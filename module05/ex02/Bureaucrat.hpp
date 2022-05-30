#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <string>

# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		// canonical
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat& toCopy);
		Bureaucrat &operator=(const Bureaucrat& toAssign);
		Bureaucrat(std::string name, unsigned int grade);

		// accessor
		std::string	getName(void) const;
		unsigned int	getGrade(void) const;
		void	setName(std::string name);
		void	setGrade(unsigned int grade);

		// exception handling
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw(); 
		};

		// member functions
		void	upgrade(void); // minus
		void	downgrade(void); // plus
		void	signForm(Form& f);
		void	executeForm(Form const& form);

	private:
		std::string	_name;
		unsigned int	_grade;
};

std::ostream	&operator<<(std::ostream& out, const Bureaucrat& b);

#endif

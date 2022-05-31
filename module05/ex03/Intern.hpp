#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>

class Form;

class	Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &toCopy);
		Intern &operator=(const Intern &toAssign);

		// exception hendling
		class	NotValidFormTypeException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// member function
		Form* makeForm(std::string formType, std::string target) const;
		Form* makeSCF(std::string target) const;
		Form* makeRRF(std::string target) const;
		Form* makePPF(std::string target) const;
};

#endif

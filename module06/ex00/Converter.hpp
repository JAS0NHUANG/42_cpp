#ifndef CONVERTER_HPP_
#define CONVERTER_HPP_

#include <string>

class Converter {
	public:
		// canonical
		Converter(void);
		~Converter(void);
		Converter(const Converter &toCopy);
		Converter &operator=(const Converter &toAssign);
	
		Converter(const std::string &str);

		// getter
		const std::string&	getStr(void) const;

		// cast operators
		operator	char() const;
		operator	int() const;
		operator	float() const;
		operator	double() const;
		
		// exception handling
		class NonDisplayableException : public std::exception {
			public:
				virtual char const * what() const throw();
		};
		class ImpossibleException : public std::exception {
			public:
				virtual char const * what() const throw();
		};

		// member functions
		void	printResults(void) const;

	private:
		std::string	_str;
};

#endif

#ifndef RRF_HPP_
#define RRF_HPP_

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		// canonical
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &toCopy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &toAssign);
		RobotomyRequestForm(std::string target);

		// accessor
		const std::string &getTarget(void) const;

		// member functions
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};

#endif

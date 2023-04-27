#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

enum error_code {
	ERR_ARG = 1,
	BAD_EXP,
};

int		rpn_calculate(int ac, char** av);
bool	check_expression(std::string expression_str);
void	print_error(int err_code);
bool	solve(std::stack<std::string> & operation_stack, char oprt_char);

#endif


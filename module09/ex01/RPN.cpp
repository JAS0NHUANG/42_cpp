#include "RPN.hpp"

void	print_error(int err_code) {
	std::string err_msg;
	if (err_code == ERR_ARG)
		err_msg = "Argument error.\n";
	if (err_code == BAD_EXP)
		err_msg = "Bad expression.";
	std::cout << "Error: " << err_msg << "\n";
}

bool check_expression(std::string expression_str) {
	for (size_t i = 0; i < expression_str.size(); i++) {
		if (expression_str[i] == ' '
			|| expression_str[i] == '+'
			|| expression_str[i] == '-'
			|| expression_str[i] == '*'
			|| expression_str[i] == '/'
			|| (expression_str[i] >= '0' && expression_str[i] <= '9')) 
		{
			if ((expression_str[i] >= '0' && expression_str[i] <= '9')
				&& (expression_str[i + 1] >= '0' && expression_str[i + 1] <= '9'))
			{
				return false;
			}
			continue ;
		}
		return false;
	}
	return true;
}

bool	solve(std::stack<std::string> & operation_stack, char oprt_char) {
	if (operation_stack.size() < 2)
		return false;

	int	x, y, result;
	std::ostringstream	oss;

	std::stringstream(operation_stack.top()) >> y;
	operation_stack.pop();
	std::stringstream(operation_stack.top()) >> x;
	operation_stack.pop();

	switch (oprt_char) {
		case '+':
			result = x + y;
			break ;
		case '-': ;
			result = x - y;
			break ;
		case '*': ;
			result = x * y;
			break ;
		case '/':
			if (y == 0)
				return false;
			result = x / y;
			break ;
	}
	oss << result;
	operation_stack.push(oss.str());

	return true;
}

int	rpn_calculate(int ac, char** av) {
	if (ac != 2)
		return ERR_ARG;

	std::string expression_str(av[1]);

	if (check_expression(expression_str) == false)
		return BAD_EXP;

	std::stack<std::string> operation_stack;

	for (size_t i = 0; i < expression_str.size(); i++) {

		switch (expression_str[i]) {
			case ' ': break;
			case '+': ;
			case '-': ;
			case '*': ;
			case '/':
				if (solve(operation_stack, expression_str[i]) == false)
					return BAD_EXP;
				break;
			default:
				operation_stack.push(std::string(1, expression_str[i]));
		}
	}
	if (operation_stack.size() != 1)
		return BAD_EXP;
	std::cout << operation_stack.top() << "\n";
	return 0;
}

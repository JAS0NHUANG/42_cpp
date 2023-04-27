#include "RPN.hpp"

int	main(int ac, char** av) {
	int	status_code = 0;
	status_code = rpn_calculate(ac, av);
	if (status_code)
		print_error(status_code);
	return status_code;
}

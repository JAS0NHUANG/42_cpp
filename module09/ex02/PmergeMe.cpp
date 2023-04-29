#include "PmergeMe.hpp"

/*******************************************************************************/
/* printer																	   */
/*******************************************************************************/
void	print_error(int error_code) {
	std::string error_msg;

	if (error_code == NO_ARG)
		error_msg = "No argument.";
	else if (error_code == TOO_MANY_ARG)
		error_msg = "Too many arguments.";
	else if (error_code == NOT_INT)
		error_msg = "Can't take non integer.";
	else if (error_code == ZERO_NEGATIVE)
		error_msg = "Can't take zero or negative integer.";
	else if (error_code == TOO_BIG)
		error_msg = "Found a non integer number(number too big).";

	std::cout << YELLOW "Error: " << error_msg << "\n" RESET;
}

/*******************************************************************************/
/* get/check arguments														   */
/*******************************************************************************/
bool	is_all_digits(char* c_string) {
	std::string cpp_string = c_string;

	if (cpp_string == "")
		return false;
	for (size_t i = 0; i < cpp_string.size(); i++ ) {
		if (((cpp_string[i] > '9') || (cpp_string[i] < '0')) && cpp_string[0] != '-') {
			return false;
		}
	}
	return true;
}

int	check_arguments(int ac, char** av) {
	long long	long_holder;
	for (int i = 1; i < ac; i++) {
		std::stringstream(av[i]) >> long_holder;
		if (long_holder > 2147483647)
			return TOO_BIG;
		if (!is_all_digits(av[i]))
			return NOT_INT;
		if (atoi(av[i]) <= 0)
			return ZERO_NEGATIVE;
	}
	return 0;
}

void	get_numbers(int ac, char** av, std::vector<int> &int_vector, std::deque<int> &int_deque) {
	for (int i = 1; i < ac; i++) {
		int_vector.push_back(atoi(av[i]));
		int_deque.push_back(atoi(av[i]));
	}
}

/*******************************************************************************/
/* merge insertion sort														   */
/*******************************************************************************/
void	last_insert(std::deque<int>& main_chain) {
	std::deque<int> main_chain_holder;
	std::deque<int> sub_chain;
	int	rest = -1;
	size_t i;

	if (main_chain.size() % 2 != 0)
		rest = main_chain[main_chain.size() - 1];

	for (i = 1; i < main_chain.size(); i += 2) {
		sub_chain.push_back(main_chain[i]);
		main_chain_holder.push_back(main_chain[i-1]);
	}
	while (i < main_chain.size()) {
		main_chain_holder.push_back(main_chain[i]);
		i++;
	}
	main_chain.clear();
	main_chain.insert(main_chain.end(), main_chain_holder.begin(), main_chain_holder.end());

	for (size_t i = 0; i < sub_chain.size(); i++) {
		int left = 0;
		int right = main_chain.size() - 1;

		while (right > left) {
			int mid = (left + right) / 2;
			if (sub_chain[i] > main_chain[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if (sub_chain[i] > main_chain[left]) {
			main_chain.insert(main_chain.begin() + left + 1, sub_chain[i]);
		} else {
			main_chain.insert(main_chain.begin() + left, sub_chain[i]);
		}
	}
	if (rest != -1) {
		for (size_t j = main_chain.size() - 1; j >=0; j--) {
			if (rest > main_chain[j]) {
				main_chain.insert(main_chain.begin() + j + 1, rest);
				break ;
			} else if (j == 0) {
				main_chain.insert(main_chain.begin(), rest);
				break;
			}
		}
	}
}


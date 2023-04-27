#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <list>
#include <utility>

#include <sys/time.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0;0m"

enum error_code {
	NO_ARG = 1,
	TOO_MANY_ARG,
	NOT_INT,
	ZERO_NEGATIVE,
	TOO_BIG,
};

/*******************************************************************************/
/* printer																	   */
/*******************************************************************************/
template<typename T>
void	print_int_array(T& int_array) {
	for (size_t i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i];
		if (i != (int_array.size() - 1) )
			std::cout << ", ";
	}
	std::cout << "\n";
}

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
	for (int i = 0; i < cpp_string.size(); i++ ) {
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
template<typename T>
void	swap_n_element(T& int_array, int n, int index) {
	if (index + (2 * n) > int_array.size())
		return;
	for (size_t i = 0; i < n; i++) {
		std::swap(int_array[index + i], int_array[index + i + n]);
	}
}

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
	std::move(begin(main_chain_holder), end(main_chain_holder), back_inserter(main_chain));

	for (size_t i = 0; i < sub_chain.size(); i++) {
		for (size_t j = main_chain.size() - 1; j >=0; j--) {
			if (sub_chain[i] > main_chain[j]) {
				main_chain.insert(main_chain.begin() + j + 1, sub_chain[i]);
				break ;
			} else if (j == 0) {
				main_chain.insert(main_chain.begin(), sub_chain[i]);
				break ;
			}
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

template<typename T>
void	find_position_and_insert(
	T& int_array,
	std::deque<int> holder_array,
	int pair_by
) {

}

template<typename T>
void	insert(T& int_array, int pair_by) {
	size_t rest = int_array.size() % pair_by;
	int	pairs = int_array.size() / pair_by;
	std::deque<int> holder_array;

	// if there is only one pair and the "rest" doesn't need to be insert
	if (pairs == 1 && rest != (pair_by / 2))
		return;

	// if there are odd number of pairs(elements), take out the last pair(element) and count it into "rest"
	if (pairs % 2 != 0 && pairs != 1) {
		pairs -= 1;
		rest += pair_by;
	}

	// take out the rest and do the insertion without them
	for (size_t i = 0; i < rest; i++) {
		holder_array.push_back(int_array[(pair_by * pairs) + i]);
	}
	int_array.erase(int_array.begin() + (pair_by * pairs), int_array.begin() + (pair_by * pairs) + rest);

	// take out all the first element(with pair_by number) and create a vector/deque of.
	std::deque<int> main_chain;
	for (int i = 0; i < pairs; i += 2) {
		for (int j = 0; j < pair_by; j++) {
			main_chain.push_back(int_array[j + i * pair_by]);
		}
	}

	for (int i = pair_by; i < int_array.size(); i += (pair_by * 2)) {
		// find the position to insert from the end of the main_chain
		for (size_t j = main_chain.size() - pair_by; j >= 0; j -= pair_by) {
			if (int_array[i] > main_chain[j]) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + j + pair_by + k, int_array[i + k]);
				}
				break ;
			} else if (j == 0) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + k, holder_array[k]);
				}
				holder_array.erase(holder_array.begin(), holder_array.begin() + pair_by);
				break ;
			}
		}
	}
	if (holder_array.size() >= pair_by) {
		for (size_t j = main_chain.size() - pair_by; j >= 0; j -= pair_by) {
			if (holder_array[0] > main_chain[j]) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + j + pair_by + k, holder_array[k]);
				}
				holder_array.erase(holder_array.begin(), holder_array.begin() + pair_by);
				break ;
			} else if (j == 0) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + k, holder_array[k]);
				}
				holder_array.erase(holder_array.begin(), holder_array.begin() + pair_by);
				break ;
			}
		}
	}
	int_array.clear();
	std::move(begin(main_chain), end(main_chain), back_inserter(int_array));

	// no insert of the rest, just add back to int_array
	std::move(begin(holder_array), end(holder_array), back_inserter(main_chain));
	int_array.clear();
	if (pair_by == 2)
		last_insert(main_chain);
	std::move(begin(main_chain), end(main_chain), back_inserter(int_array));
}

template<typename T>
void	merge_insertion_sort(T& array, int pair_by) {
/* first pair_by 1, then pair_by 2, then 4 ...etc */
/* if the size of array / pair_by * 2 is 1, stop the recursion */
	if (array.size() / pair_by  == 1) {
		return ;
	}

/* iterate through the array and find the smallist inside each pair */
	for (size_t i = 0; i < array.size(); i += (pair_by * 2)) {
		if (i + pair_by > array.size())
			break;
		if (array[i] > array[i + pair_by]) {
			swap_n_element(array, pair_by, i);
		}
	}

	pair_by *= 2;
	merge_insertion_sort(array, pair_by);
	// after all the recursion and pair sorting, do the insertion
	insert(array, pair_by);
}

/*******************************************************************************/
/* main 																	   */
/*******************************************************************************/
int main(int ac, char **av) {
	// check errors
	int	error_code;
	if (ac > 3001) {
		print_error(TOO_MANY_ARG);
		return TOO_MANY_ARG;
	} else if (ac < 2) {
		print_error(NO_ARG);
		return NO_ARG;
	} else if ((error_code = check_arguments(ac, av)) != 0) {
		print_error(error_code);
		return error_code;
	}

	// store arguments into vector and deque
	std::vector<int> int_vector;
	std::deque<int> int_deque;
	get_numbers(ac, av, int_vector, int_deque);


	// start operation and timer
	struct timeval	time_start, time_end;
	long long	v_start, v_end, d_start, d_end, v_diff, d_diff;

	std::cout << "Before:\t";
	print_int_array(int_deque);

	// start counting time and sort vector
	if (gettimeofday(&time_start, NULL))
		return (1);
	merge_insertion_sort(int_vector, 1);
	if (gettimeofday(&time_end, NULL))
		return (1);
	// calculate time used
	v_start = time_start.tv_usec;
	v_end = time_end.tv_usec;
	v_diff = v_end - v_start;

	// start counting time and sort deque
	if (gettimeofday(&time_start, NULL))
		return (1);
	merge_insertion_sort(int_vector, 1);
	if (gettimeofday(&time_end, NULL))
		return (1);
	// calculate time used
	d_start = time_start.tv_usec;
	d_end = time_end.tv_usec;
	d_diff = d_end - d_start;

	std::cout << "After:\t";
	print_int_array(int_vector);

	std::cout << "Time to process a range of \t" <<  ac - 1 << "\t"
		<< " elements with std::vector :\t" << v_diff << "us\n";
	std::cout << "Time to process a range of \t" <<  ac - 1 << "\t"
		<< " elements with std::deque :\t" << d_diff << "us\n";

}

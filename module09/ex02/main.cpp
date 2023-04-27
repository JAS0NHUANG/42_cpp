#include "PmergeMe.hpp"

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
	std::cout << "Before:\t";
	print_int_array(int_deque);

	// start operation and timer
	struct timeval	time_start, time_end;
	long long	v_start, v_end, d_start, d_end, v_diff, d_diff;

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
	std::cout << "Time to process a range of \t" <<  ac - 1
		<< " elements with std::vector:\t" << v_diff << "\tus\n";
	std::cout << "Time to process a range of \t" <<  ac - 1
		<< " elements with std::deque:\t" << d_diff << "\tus\n";

}

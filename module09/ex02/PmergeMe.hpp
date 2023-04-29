#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <list>
# include <utility>

# include <sys/time.h>
# include <stdlib.h>

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
			std::cout << " ";
	}
	std::cout << "\n";
}

void	print_error(int error_code);

/*******************************************************************************/
/* get/check arguments														   */
/*******************************************************************************/
bool	is_all_digits(char* c_string);
int		check_arguments(int ac, char** av);
void	get_numbers(int ac, char** av, std::vector<int> &int_vector, std::deque<int> &int_deque);

/*******************************************************************************/
/* merge insertion sort														   */
/*******************************************************************************/
void	last_insert(std::deque<int>& main_chain);

template<typename T>
void	swap_n_element(T& int_array, int n, int index) {
	if (index + (2 * n) > (int)int_array.size())
		return;
	for (int i = 0; i < n; i++) {
		std::swap(int_array[index + i], int_array[index + i + n]);
	}
}

template<typename T>
void	insert(T& int_array, int pair_by) {
	size_t rest = int_array.size() % pair_by;
	int	pairs = int_array.size() / pair_by;
	std::deque<int> holder_array;

	// if there is only one pair and the "rest" doesn't need to be insert
	if (pairs == 1 && (int)rest != (pair_by / 2))
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

	for (size_t i = pair_by; i < int_array.size(); i += (pair_by * 2)) {
		// find the position to insert from the end of the main_chain
		for (size_t j = main_chain.size() - pair_by; j >= 0; j -= pair_by) {
			if (int_array[i] > main_chain[j]) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + j + pair_by + k, int_array[i + k]);
				}
				break ;
			} else if (j == 0) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + k, int_array[i + k]);
				}
				break ;
			}
		}
	}
	if ((int)holder_array.size() >= pair_by) {
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

	// no insert of the rest, just add back to int_array
	main_chain.insert(main_chain.end(), holder_array.begin(), holder_array.end());
	int_array.clear();
	if (pair_by == 2)
		last_insert(main_chain);
	int_array.insert(int_array.end(), main_chain.begin(), main_chain.end());
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


#endif

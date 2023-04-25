#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <utility>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0;0m"

/*******************************************************************************/
/* printer																	   */
/*******************************************************************************/
template<typename T>
void	print_int_array(T& int_array) {
	std::cout << "array length: " << int_array.size();
	std::cout << "\narray content: ";
	for (int i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i];
		if (i != (int_array.size() - 1) )
			std::cout << ", ";
	}
	std::cout << "\n";
}

void	print_error(int error_code) {
}

/*******************************************************************************/
/* get/check arguments														   */
/*******************************************************************************/
int	check_arguments(int ac, char** av) {
	return 0;
}

int	get_numbers(int ac, char** av, std::vector<int> &int_vector, std::deque<int> &int_deque) {
	return 0;
}

/*******************************************************************************/
/* merge insertion sort														   */
/*******************************************************************************/
template<typename T>
void	swap_n_element(T& int_array, int n, int index) {
	std::cout << "the N: " << n << "\n";
	if (index + (2 * n) > int_array.size())
		return;
	for (int i = 0; i < n; i++) {
		std::cout << "swaping a: " << int_array[index + i] << " b: "<< int_array[index + i + n] << "\n";
		std::swap(int_array[index + i], int_array[index + i + n]);
		print_int_array(int_array);
	}
}

void	last_insert(std::deque<int>& main_chain) {
	std::deque<int> main_chain_holder;
	std::deque<int> sub_chain;
	int	rest = -1;
	int i;

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

	for (int i = 0; i < sub_chain.size(); i++) {
		for (int j = main_chain.size() - 1; j >=0; j--) {
			if (sub_chain[i] > main_chain[j]) {
				main_chain.insert(main_chain.begin() + j + 1, sub_chain[i]);
				break ;
			} else if (j == 0) {
				main_chain.insert(main_chain.begin(), sub_chain[i]);
			}
		}
	}
	if (rest != -1) {
		for (int j = main_chain.size() - 1; j >=0; j--) {
			if (rest > main_chain[j]) {
				main_chain.insert(main_chain.begin() + j + 1, rest);
				break ;
			} else if (j == 0) {
				main_chain.insert(main_chain.begin(), sub_chain[i]);
			}
		}
	}
}

template<typename T>
void	insert(T& int_array, int pair_by) {
	std::cout << YELLOW << "before insert!!\n" << RED;
	print_int_array(int_array);
	int rest = int_array.size() % pair_by;
	int	pairs = int_array.size() / pair_by;
	std::deque<int> holder_array;

	if (pairs == 1 && rest != pair_by)
		return;
	if (pairs % 2 != 0 && pairs != 1) {
		pairs -= 1;
		rest += pair_by;
	}
	// take out the rest and do the insertion without them
	for (int i = 0; i < rest; i++) {
		holder_array.push_back(int_array[(pair_by * pairs) + i]);
	}
	int_array.erase(int_array.begin() + (pair_by * pairs), int_array.begin() + (pair_by * pairs) + rest);
	std::cout << "int_array : " ;
	print_int_array(int_array);
	std::cout << "holder_array : " ;
	print_int_array(holder_array);
	std::cout << "\n";


	// take out all the first element(with pair_by number) and create a vector/deque of.
	std::deque<int> main_chain;
	for (int i = 0; i < pairs; i += 2) {
		for (int j = 0; j < pair_by; j++) {
			main_chain.push_back(int_array[j + i * pair_by]);
		}
	}
	std::cout << "main_chain before: " ;
	print_int_array(main_chain);
	std::cout << "\n";

	for (int i = pair_by; i < int_array.size(); i += (pair_by * 2)) {
		// find the position to insert from the end of the main_chain
		for (int j = main_chain.size() - pair_by; j >= 0; j -= pair_by) {
			if (int_array[i] > main_chain[j]) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + j + pair_by + k, int_array[i + k]);
				}
				break ;
			}
		}
	}
	std::cout << "main_chain after: " ;
	print_int_array(main_chain);
	std::cout << "\n";
	int_array.clear();
	std::move(begin(main_chain), end(main_chain), back_inserter(int_array));

	// no insert of the rest, just add back to int_array
	std::cout << "just add rest to the back !!!!! \n";
	std::cout << "holder: ";
	print_int_array(holder_array);
	print_int_array(main_chain);
	std::move(begin(holder_array), end(holder_array), back_inserter(main_chain));
	print_int_array(main_chain);
	int_array.clear();
	if (pair_by == 2)
		last_insert(main_chain);
	std::move(begin(main_chain), end(main_chain), back_inserter(int_array));
	print_int_array(int_array);
	std::cout << "The N:: " << pair_by << "\n";
	std::cout << YELLOW <<  "insert finished\n\n" << RESET;
}

template<typename T>
void	merge_insertion_sort(T& array, int pair_by) {
/* first pair_by 1, then pair_by 2, then 4 ...etc */
/* if the size of array / pair_by * 2 is 1, stop the recursion */
	if (array.size() / pair_by  == 1) {
		return ;
	}

/* iterate through the array and find the smallist inside each pair */
	for (int i = 0; i < array.size(); i += (pair_by * 2)) {
		if (array[i] > array[i + pair_by]) {
			swap_n_element(array, pair_by, i);
		}
	}

	pair_by *= 2;
	merge_insertion_sort(array, pair_by);
	std::cout << RED;
	// after all the recursion and pair sorting, do the insertion
	insert(array, pair_by);
}

/*******************************************************************************/
/* main 																	   */
/*******************************************************************************/
int main(int ac, char **av) {
	if (check_arguments(ac, av) != 0) {
		print_error(1);
		return 1;
	}
	std::vector<int> int_vector;
	std::deque<int> int_deque;
	if (get_numbers(ac, av, int_vector, int_deque) != 0) {
		print_error(2);
		return 2;
	}
	/*
	// sort vectors
	std::vector<int> vector_a = {1, 3, 5, 22, 44};
	std::vector<int> vector_b = {98,  76, 199, 2, 3 ,44, 5, 5};
	print_int_array(vector_a);
	print_int_array(vector_b);

	//merge_insertion_sort(vector_a, 1);
	std::cout << "\n";
	*/

	// sort deques
	std::deque<int> deque_a = {7, 1, 3, 5, 22, 13};
	// size 20
	std::deque<int> deque_b = {87, 65 ,0, 98,  76, 199, 2, 3 ,44, 188 , 99, 5, 38, 1, 4, 7, 6, 9, 8, 10, 14, 27, 110};
	std::deque<int> deque_c = {98,  76, 199, 2, 3 ,44, 188 , 99, 5};

	std::cout << "\n\nbefore sort: \n";
	print_int_array(deque_a);
	print_int_array(deque_b);
	print_int_array(deque_c);

	std::cout << "\n\nsort deques: \n";
	//merge_insertion_sort(deque_a, 1);
	merge_insertion_sort(deque_b, 1);
	//merge_insertion_sort(deque_c, 1);

	std::cout << "After sort: ";
	print_int_array(deque_a);
	print_int_array(deque_b);
	print_int_array(deque_c);
}

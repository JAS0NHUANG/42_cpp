#include <iostream>
#include <vector>
#include <utility>

void	swap_x(std::vector<int>& the_vector, int level, int index_a, int index_b) {
		int	index_add = 0;
		std::cout << "swaping!!!!\n";
		while (index_add < level / 2) {
			std::cout << "a, b: " << the_vector[index_a + index_add] << ", "<< the_vector[index_b + index_add] << "\n";
			std::swap(the_vector[index_a + index_add], the_vector[index_b + index_add]);
			std::cout << "after a, b: " << the_vector[index_a + index_add] << ", "<< the_vector[index_b + index_add] << "\n";
			index_add++;
		}
}

void	print_vector(std::vector<int> the_vector) {
	std::vector<int>::const_iterator vector_it;
	for(vector_it = the_vector.begin(); vector_it != the_vector.end(); vector_it++) {
		std::cout << (*vector_it) << "\n";
	}
}


void	last_insert(std::vector<int> the_vector) {
}

void	merge_insert_sort(std::vector<int>& the_vector, int level) {
	level *= 2;
	int	round = the_vector.size();
	std::cout << "\n round: " << round << "\n";
	std::cout << " level: " << level << "\n";

	for (int i = 0; i < round; i += (level)) {
		std::cout << "i: " << i << "\n";
		if (the_vector[i] > the_vector[i + level / 2]) {
			swap_x(the_vector, level, i, i + (level / 2));
		}
	}

	if (round = 1) {
		last_insert(the_vector);
		return;
	}

	// call it again for the next level sort.
	merge_insert_sort(the_vector, level);
}


int main() {
	std::vector<int> a = {2, 1 , 6, 10, 3 , 5, 8,9, 12 , 11};

	print_vector(a);

	merge_insert_sort(a, 1);

	print_vector(a);




	return 0;
}

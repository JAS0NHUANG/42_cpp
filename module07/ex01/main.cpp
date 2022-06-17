#include "iter.hpp"

int main(void) {

	std::cout << " ~~~~~ int test ~~~~~ \n";
	{
		int	array[] = {1, 2, 3, 4, 5};
		iter (array, 5, print);
		std::cout << "\n";

		iter (array, 5, add);
		iter (array, 5, print);
		std::cout << "\n";
	}
	std::cout << "\n";

	std::cout << " ~~~~~ float test ~~~~~ \n";
	{
		float	array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		iter (array, 5, print);
		std::cout << "\n";

		iter (array, 5, add);
		iter (array, 5, print);
		std::cout << "\n";
	}
	std::cout << "\n";

	std::cout << " ~~~~~ char test ~~~~~ \n";
	{
		char	array[] = {'h', 'e', 'l', 'l', 'o'};
		iter (array, 5, print);
		std::cout << "\n";

		iter (array, 5, add);
		iter (array, 5, print);
		std::cout << "\n";
	}

	std::cout << " ~~~~~ string test ~~~~~ \n";
	{
		std::string	array[] = {"hello", "this", "is", "an", "array"};
		iter (array, 5, print);
		std::cout << "\n";
		/* can't compile this
		iter (array, 5, add);
		*/
	}
	std::cout << "\n";

}

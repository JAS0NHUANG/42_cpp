#include "iter.hpp"

int main(void) {
	{
		int	array[] = {1, 2, 3, 4, 5};
		iter (array, 5, print);
		std::cout << "\n";

		iter (array, 5, add);
		iter (array, 5, print);
		std::cout << "\n";
	}
	{
		std::string	array[] = {"hello", "this", "is", "an", "array"};
		iter (array, 5, print);
		std::cout << "\n";

		/* can't increment on string
		iter (array, 5, add);
		*/
	}
	{
		char	array[] = {'h', 'e', 'l', 'l', 'o'};
		iter (array, 5, print);
		std::cout << "\n";

		iter (array, 5, add);
		iter (array, 5, print);
		std::cout << "\n";
	}
}

#include <iostream>
#include <cstdlib>
#include <string>

#include "Array.hpp"
template<typename T>
void	printArray(T & array) {
	unsigned int size = array.size();
	for (unsigned int i = 0; i < size; i++) {
		std::cout << array[i];
		if (i != size - 1)
			std::cout << ", ";
		else
			std::cout << "\n";
	}
}

int	main(int, char**) {
	{
		int	* a = new int();
		char * b = new char();
		std::string * c = new std::string();
		std::cout << "the int: " << a << "\n";
		std::cout << "the char: " << b << "\n";
		std::cout << "the str: " << c << "\n";
		delete a;
		delete b;
		delete c;
	}
	std::cout << "\n";

	std::cout << " ~~~~~ Empty Array ~~~~~ \n";
	{
		Array<int> a = Array<int>();
		std::cout << "the int array addr: " << &a << "\n";
		std::cout << "array size: " << a.size() << "\n";
		try {
			std::cout << "array[0] " << a[0] << "\n";
		} catch (std::exception & e) {
			std::cout << e.what() << "\n";
		}
	}
	std::cout << "\n";

	std::cout << " ~~~~~ Int Array ~~~~~ \n";
	{
		Array<int> a = Array<int>(10);
		std::cout << "the int array addr: " << &a << "\n";
		std::cout << "array size: " << a.size() << "\n";
		printArray(a);
	}
	std::cout << "\n";


	std::cout << " ~~~~~ Copy int Array (should be a deep copy) ~~~~~ \n";
	{
		Array<int> a = Array<int>(10);
		Array<int>  b = a;
		std::cout << "the int array a addr: " << &a << "\n";
		std::cout << "the int array b addr: " << &b << "\n";
		std::cout << "array size: " << a.size() << "\n";
		std::cout << "array size: " << b.size() << "\n";
		std::cout << "before modification:\n";
		printArray(a);
		printArray(b);
		a[1] = 42;
		b[1] = 33;
		std::cout << "after modification(set b[1] to 33 and a[1] to 42) :\n";
		printArray(a);
		printArray(b);
	}
	std::cout << "\n";

	std::cout << " ~~~~~ Char Array ~~~~~ \n";
	{
		Array<char> a = Array<char>(10);
		std::cout << "the char array addr: " << &a << "\n";
		std::cout << "array size: " << a.size() << "\n";
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = ('a' + i);
		printArray(a);
	}
	std::cout << "\n";

	std::cout << " ~~~~~ String Array ~~~~~ \n";
	{
		Array<std::string> a = Array<std::string>(10);
		std::cout << "the char array addr: " << &a << "\n";
		std::cout << "array size: " << a.size() << "\n";
		a[0] = "Hello";
		a[1] = "world";
		a[2] = "!";
		printArray(a);
		std::cout << "\n";

		std::cout << " ~~~~~ try out of bound ~~~~~ \n";
		try {
			std::cout << "the 11th element: " << a[11] << "\n";
		} catch (std::exception & e) {
			std::cout << e.what() << "\n";
		}
		try {
			std::cout << "the 12th element: " << a[12] << "\n";
		} catch (std::exception & e) {
			std::cout << e.what() << "\n";
		}
		try {
			std::cout << "a negative element: " << a[-324234] << "\n";
		} catch (std::exception & e) {
			std::cout << e.what() << "\n";
		}
	}


}

/* main in subjcet
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		std::cout << numbers[i] << "\n";
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	mirror[2]++;
	numbers[2]--;
	std::cout << "Mirror 2: " << mirror[2] << "Number 2: " << numbers[2] << "\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

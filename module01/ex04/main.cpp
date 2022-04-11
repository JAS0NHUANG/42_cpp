#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av) {
	if (ac != 4)
	{
		std::cerr << "Wrong amount of arguments.\n";
		return (1);
	}
	std::string filename = av[1];
	std::ifstream the_file(av[1]);
	std::ofstream replace_file(filename.append(".replace").c_str());

	if (the_file.is_open()) {
		std::string the_string;
		std::string str_to_find = av[2];
		std::string str_to_replace = av[3];
		std::size_t found_i = 0;
		std::size_t index = 0;
		std::cout << "init found: " << found_i << "\n";

		while (getline(the_file, the_string)) {
			index = 0;
			found_i = the_string.find(str_to_find);
			std::cout << the_string << "\n";
			while (found_i != std::string::npos)
			{
				std::cout << "found: " << found_i << "\n";
				/* can't use replace.... :'(
				the_string.replace(found_i, 1, "kkkkk");\
				*/
				std::cout << "index to found_i: " << index << " / " << found_i << "\n";
				replace_file << the_string.substr(index, found_i - index);
				replace_file << str_to_replace;
				index = found_i + str_to_find.length();
				std::cout << "index: " << index << "\n";
				found_i = the_string.find(str_to_find, index);
			}
			if (index < the_string.length())
				replace_file << the_string.substr(index, the_string.length() - index);
			replace_file << "\n";
		}

	} else {
		std::cout << "Error opening file: " << av[1] << "\n";
	}
	return (0);
}

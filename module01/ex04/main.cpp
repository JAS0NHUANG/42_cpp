#include <fstream>
#include <iostream>
#include <string>

int	return_err(int err_code, char *filename)
{
	if (err_code == 1)
		std::cerr << "Wrong amount of arguments.\n";
	if (err_code == 2)
		std::cerr << "Error opening file: " << filename << "\n";
	return (err_code);
}

int	replace_string_in_file(std::string to_find, std::string to_replace,
		std::fstream &the_file, std::string filename)
{
	std::ofstream replace_file(filename.append(".replace").c_str());
	if (!replace_file)
		return (1);
	std::string str_buff;
	std::size_t found_i = 0;
	std::size_t index = 0;
	while (getline(the_file, str_buff)) {
		index = 0;
		found_i = str_buff.find(to_find);
		while (found_i != std::string::npos)
		{
			replace_file << str_buff.substr(index, found_i - index);
			replace_file << to_replace;
			index = found_i + to_find.length();
			found_i = str_buff.find(to_find, index);
		}
		if (index < str_buff.length())
			replace_file << str_buff.substr(index, str_buff.length() - index);
		replace_file << "\n";
	}
	return (0);
}

int	main(int ac, char **av) {
	if (ac != 4 || av[2][0] == '\0')
		return (return_err(1, NULL));
	std::string filename = av[1];
	std::fstream the_file;

	the_file.open(av[1], std::ios_base::in);
	if (the_file.is_open()) {
		std::string to_find = av[2];
		std::string to_replace = av[3];
		if (replace_string_in_file(to_find, to_replace, the_file, filename))
			return (return_err(2, av[1]));
	} else
		return (return_err(2, av[1]));
	return (0);
}

#include <iostream>
#include <fstream>
#include <string>

#define BLACK	"\033[1;30m"
#define RED		"\033[1;31m"
#define RESET	"\033[0m"

std::string	ft_replace(std::string haystack, std::string needle, std::string str)
{
	std::size_t	pos;

	pos = haystack.find(needle);
	while (pos != std::string::npos)
	{
		haystack.erase(pos, needle.length());
		haystack.insert(pos, str);
		pos = haystack.find(needle, pos + str.length());
	}
	return (haystack);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << RED << "ERROR: Wrong arguments' number" << RESET << std::endl;
		std::cout << BLACK << "usage: <filename> <string1> <string2>" << RESET << std::endl;
		return (1);
	}

	std::ofstream	outfile;
	std::fstream	infile;
	std::string		outFileName;
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);

	if (!s1.length())
	{
		std::cout << RED << "ERROR: second argumant is empty" << RESET << std::endl;
		std::cout << BLACK << "usage: <filename> <string1> <string2>" << RESET << std::endl;
		return (0);
	}
	outFileName = std::string(argv[1]) + ".replace";

	infile.open(argv[1], std::ios::in);

	if (infile.is_open())
	{
		outfile.open(outFileName.c_str(), std::ios::out);
		if (outfile.is_open())
		{
			std::string		line;
			while(std::getline(infile, line))
				outfile << ft_replace(line, s1, s2) << std::endl;
			outfile.close();
		}
		else
			std::cout << RED << "ERROR: Couldn't create file \"" << outFileName << "\"" << RESET << std::endl;
		infile.close();
	}
	else
		std::cout << RED << "ERROR: Couldn't open file \"" << argv[1] << "\"" << RESET << std::endl;
	return (0);
}

#include "Harl.hpp"

void	harl_switch(std::string level)
{
	std::string	levels[4] = { "debug", "info", "warning", "error" };
	Harl		harl;
	int			i;

	for (i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
			break;
	}

	switch(i)
	{
		case 0:
			harl.complain("debug");
			// fallthrough
		case 1:
			harl.complain("info");
			// fallthrough
		case 2:
			harl.complain("warning");
			// fallthrough
		case 3:
			harl.complain("error");
			break;
		default:
			std::cout << "Unknown level: \"" << level << "\"" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "ERROR: Wrong arguments' number" << RESET << std::endl;
		std::cout << BLACK << "usage: <debug level>" << RESET << std::endl;
		return (1);
	}
	harl_switch(argv[1]);
	return (0);
}
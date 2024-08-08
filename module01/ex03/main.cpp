#include "Weapon.hpp"
#include <iostream>

int	main(void)
{
	Weapon	w;
	std::string	s = "sometype";
	std::string&	ref = s;

	std::cout << "type: " << w.getType() << std::endl;
	w.setType(ref);
	std::cout << "type: " << w.getType() << std::endl;
	return (0);
}

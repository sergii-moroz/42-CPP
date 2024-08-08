#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const & name, std::string const & type) : _name(name)
{
	_weapon.setType(type);
};

HumanA::~HumanA( void ){};

void	HumanA::attack( void )
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

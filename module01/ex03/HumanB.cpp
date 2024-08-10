#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string const & name ) : _name(name), _weapon(NULL)
{};

HumanB::~HumanB( void ){};

void	HumanB::attack( void )
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack" << std::endl;
}

void	HumanB::setWeapon( Weapon const & weapon )
{
	_weapon = &weapon;
}

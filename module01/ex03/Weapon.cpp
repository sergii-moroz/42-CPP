#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::~Weapon(){}

std::string const &	Weapon::getType( void )
{
	return (this->_type);
}

void	Weapon::setType(std::string const & type)
{
	this->_type = type;
}

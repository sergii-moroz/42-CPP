#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "noname: created" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << _name << ": destroied" <<std::endl;
}

Zombie::Zombie( std::string name) : _name(name)
{
	std::cout << _name << ": created" << std::endl;
};

void	Zombie::announce( void ) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name)
{
	_name = name;
}

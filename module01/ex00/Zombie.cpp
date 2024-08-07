#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "Zombie " << _name << "created" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << _name << ": destroied" <<std::endl;
}

Zombie::Zombie( std::string name) : _name(name)
{
	announce();
};

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

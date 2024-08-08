#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ) const;
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif

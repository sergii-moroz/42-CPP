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
		void	setName( std::string name);
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
Zombie*	zombieHorde( int N, std::string name );

#endif

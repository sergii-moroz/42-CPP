#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;
		void	announce( void );
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void	randomChump( std::string name );
};


#endif

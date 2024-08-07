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
		Zombie( std::string );
		~Zombie( void );
};


#endif

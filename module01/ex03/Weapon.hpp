#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon();
		~Weapon();
		std::string const &	getType( void );
		void	setType( std::string const & type);
};


#endif

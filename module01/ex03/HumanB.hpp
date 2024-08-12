#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		const *_weapon;
	public:
		HumanB( std::string const & name);
		~HumanB( void );
		void	attack( void );
		void	setWeapon( Weapon const & weapon);
};

#endif

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string		_name;
		Weapon const &	_weapon;
	public:
		HumanA( std::string const & name, Weapon const & weapon );
		~HumanA( void );
		void	attack( void ) const;
};

#endif

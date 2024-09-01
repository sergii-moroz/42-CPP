/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:18:41 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/31 13:18:41 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Diamond_TRAP_HPP
# define Diamond_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap( DiamondTrap const & );
		DiamondTrap( std::string const & );
		DiamondTrap & operator=( DiamondTrap const & );
		~DiamondTrap();

		std::string	getName() const;
		void		setName(std::string const & name );

		void		attack(std::string const & target);
		void		whoAmI();
};

std::ostream & operator<<(std::ostream & out, DiamondTrap const & st);

#endif

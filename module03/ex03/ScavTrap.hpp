/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:18:41 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/31 13:18:41 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( ScavTrap const & );
		ScavTrap( std::string const & );
		ScavTrap & operator=( ScavTrap const & );
		~ScavTrap();

		void		attack(std::string const & target);
		void		guardGate();
};

std::ostream & operator<<(std::ostream & out, ScavTrap const & st);

#endif
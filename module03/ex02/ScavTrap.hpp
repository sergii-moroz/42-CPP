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

class ScavTrap : public ClapTrap
{
	private:
		bool	_guardGate;
	public:
		ScavTrap();
		ScavTrap( ScavTrap const & );
		ScavTrap( std::string const & );
		ScavTrap & operator=( ScavTrap const & );
		~ScavTrap();

		bool		getGuardGate() const;
		void		setGuardGate( bool );

		void		attack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		guardGate();
};

std::ostream & operator<<(std::ostream & out, ScavTrap const & st);

#endif

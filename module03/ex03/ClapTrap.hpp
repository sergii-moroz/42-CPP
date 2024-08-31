/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:40:40 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/26 10:30:04 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & copy);
		~ClapTrap();

		std::string		getName() const;
		unsigned int	getHitPoints() const ;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		void			setName(std::string const & name );
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoints(unsigned int epoints);
		void			setAttackDamage(unsigned int damage);

		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		ClapTrap & operator=( ClapTrap const & ct );
};

std::ostream & operator<<(std::ostream & out, ClapTrap const & ct);

#endif

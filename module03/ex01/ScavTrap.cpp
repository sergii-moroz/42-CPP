/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:19:42 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/31 13:19:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// =========================================================
// constructors
// =========================================================

ScavTrap::ScavTrap()
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	setGuardGate(false);
	std::cout <<  "ScavTrap[ " << getName() << " ] : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	setGuardGate(false);
	std::cout << "ScavTrap[ " << getName() << " ] : named constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy)
{
	setGuardGate(copy.getGuardGate());
	std::cout << "ScavTrap[ " << getName() << " ] : Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap[ " << getName() << " ] : Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

bool	ScavTrap::getGuardGate() const
{
	return (_guardGate);
}

void	ScavTrap::setGuardGate( bool guarding )
{
	_guardGate = guarding;
}

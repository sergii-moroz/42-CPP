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
	std::cout <<  "ScavTrap[ " << getName() << " ] : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap[ " << getName() << " ] : named constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy)
{
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
// Assignment = operator's overloading
// =========================================================

ScavTrap & ScavTrap::operator=(ScavTrap const & copy)
{
	setName( copy.getName() );
	setHitPoints( copy.getHitPoints() );
	setEnergyPoints( copy.getEnergyPoints() );
	setAttackDamage( copy.getAttackDamage() );
	return (*this);
}

// =========================================================
// member functions
// =========================================================

void	ScavTrap::guardGate()
{
	if (getHitPoints() <= 0)
		std::cout << "ScavTrap: " << getName() << " is not able to enter in gate keeper mode"
			<< ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	if (getHitPoints() > 0)
		std::cout << "ScavTrap[ " << getName() << " ] : is now in Gate Keeper mode" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	if (getAttackDamage() <= 0)
		std::cout << "ScavTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getAttackDamage()
			<< " attack damage points" << std::endl;
	else if (getEnergyPoints() < 1)
		std::cout << "ScavTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getEnergyPoints()
			<< " energy points" << std::endl;
	else if (getHitPoints() <= 0)
		std::cout << "ScavTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	if (getAttackDamage() > 0 && getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks "
			<< target << ", causing " << getAttackDamage()
			<< " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, ScavTrap const & st)
{
	out << "ScavTrap:" << std::endl
		<< "{" << std::endl
		<< "\tname: " << st.getName() << std::endl
		<< "\thit points: " << st.getHitPoints() << std::endl
		<< "\tenergy points: " << st.getEnergyPoints() << std::endl
		<< "\tattack damage: " << st.getAttackDamage() << std::endl
		<< "}" << std::endl;
	return (out);
}

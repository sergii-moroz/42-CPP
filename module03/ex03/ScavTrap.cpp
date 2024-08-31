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

// =========================================================
// Assignment = operator's overloading
// =========================================================

ScavTrap & ScavTrap::operator=(ScavTrap const & copy)
{
	setName( copy.getName() );
	setHitPoints( copy.getHitPoints() );
	setEnergyPoints( copy.getEnergyPoints() );
	setAttackDamage( copy.getAttackDamage() );
	setGuardGate(copy.getGuardGate());
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
	{
		if (getGuardGate())
			std::cout << "ScavTrap[ " << getName() << " ] : is already keep the Gate." << std::endl;
		else
		{
			std::cout << "ScavTrap[ " << getName() << " ] : has entered the Gate Keeper mode" << std::endl;
			setGuardGate(true);
		}
	}
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "It has no senseto to attack ScavTrap" << getName()
			<< " he has " << getHitPoints() << " hit points" << std::endl;
		return ;
	}
	setHitPoints(getHitPoints() - amount);
	std::cout << "ScavTrap " << getName() << " takes "
		<< amount << " points of damage!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() < 1)
		std::cout << "ScavTrap: " << getName() << " is not able to repair itself"
			<< ", because he has " << getEnergyPoints()
			<< " energy points" << std::endl;
	else if (getHitPoints() <= 0)
		std::cout << "ScavTrap: " << getName() << " is not able to repair itself"
			<< ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	else if (getHitPoints() >= 100)
		std::cout << "ScaveTrap: " << getName() << " is not able to repair itself"
			<< ", because he has maximum amount of hit points: " << getHitPoints() << std::endl;
	if (getHitPoints() > 0 && getHitPoints() < 100 && getEnergyPoints() > 0 )
	{
		if (getHitPoints() + amount > 100)
			setHitPoints(100);
		else
			setHitPoints(getHitPoints() + amount);
		std::cout << "ScaveTrap " << getName() << " recovers "
			<< amount << " hit points!" << std::endl;
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
		<< "\tis guarding gate: " << st.getGuardGate() << std::endl
		<< "}" << std::endl;
	return (out);
}

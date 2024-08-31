/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:19:42 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/31 13:19:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// =========================================================
// constructors
// =========================================================

FragTrap::FragTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout <<  "FragTrap[ " << getName() << " ] : Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap[ " << getName() << " ] : named constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & copy) : ClapTrap(copy)
{
	std::cout << "FragTrap[ " << getName() << " ] : Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

FragTrap::~FragTrap()
{
	std::cout << "FragTrap[ " << getName() << " ] : Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

FragTrap & FragTrap::operator=(FragTrap const & copy)
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

void	FragTrap::highFivesGuys()
{
	if (getHitPoints() <= 0)
		std::cout << "FragTrap: " << getName() << " is not able to give high fives"
			<< ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	if (getHitPoints() > 0)
	{
		std::cout << "FragTrap[ " << getName() << " ] : High Five man" << std::endl;
	}
}

void	FragTrap::attack(std::string const & target)
{
	if (getAttackDamage() <= 0)
		std::cout << "FragTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getAttackDamage()
			<< " attack damage points" << std::endl;
	else if (getEnergyPoints() < 1)
		std::cout << "FragTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getEnergyPoints()
			<< " energy points" << std::endl;
	else if (getHitPoints() <= 0)
		std::cout << "FragTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	if (getAttackDamage() > 0 && getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "FragTrap " << getName() << " attacks "
			<< target << ", causing " << getAttackDamage()
			<< " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "It has no senseto to attack FragTrap" << getName()
			<< " he has " << getHitPoints() << " hit points" << std::endl;
		return ;
	}
	setHitPoints(getHitPoints() - amount);
	std::cout << "FragTrap " << getName() << " takes "
		<< amount << " points of damage!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() < 1)
		std::cout << "FragTrap: " << getName() << " is not able to repair itself"
			<< ", because he has " << getEnergyPoints()
			<< " energy points" << std::endl;
	else if (getHitPoints() <= 0)
		std::cout << "FragTrap: " << getName() << " is not able to repair itself"
			<< ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	else if (getHitPoints() >= 100)
		std::cout << "FrageTrap: " << getName() << " is not able to repair itself"
			<< ", because he has maximum amount of hit points: " << getHitPoints() << std::endl;
	if (getHitPoints() > 0 && getHitPoints() < 100 && getEnergyPoints() > 0 )
	{
		if (getHitPoints() + amount > 100)
			setHitPoints(100);
		else
			setHitPoints(getHitPoints() + amount);
		std::cout << "FrageTrap " << getName() << " recovers "
			<< amount << " hit points!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, FragTrap const & st)
{
	out << "FragTrap:" << std::endl
		<< "{" << std::endl
		<< "\tname: " << st.getName() << std::endl
		<< "\thit points: " << st.getHitPoints() << std::endl
		<< "\tenergy points: " << st.getEnergyPoints() << std::endl
		<< "\tattack damage: " << st.getAttackDamage() << std::endl
		<< "}" << std::endl;
	return (out);
}

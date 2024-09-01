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

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, FragTrap const & ft)
{
	out << "FragTrap:" << std::endl
		<< "{" << std::endl
		<< "\tname: " << ft.getName() << std::endl
		<< "\thit points: " << ft.getHitPoints() << std::endl
		<< "\tenergy points: " << ft.getEnergyPoints() << std::endl
		<< "\tattack damage: " << ft.getAttackDamage() << std::endl
		<< "}" << std::endl;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:19:42 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/31 13:19:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// =========================================================
// constructors
// =========================================================

DiamondTrap::DiamondTrap()
{
	setName("noname_DiamondTrap");
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout <<  "DiamondTrap[ " << getName() << " ] : Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name")
{
	setName(name);
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap[ " << getName() << " ] : named constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	setName(copy.getName());
	std::cout << "DiamondTrap[ " << getName() << " ] : Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap[ " << getName() << " ] : Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & copy)
{
	setName( copy.getName() );
	setHitPoints( copy.getHitPoints() );
	setEnergyPoints( copy.getEnergyPoints() );
	setAttackDamage( copy.getAttackDamage() );
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	DiamondTrap::getName() const
{
	return (this->_name);
}

void	DiamondTrap::setName( std::string const & name )
{
	_name = name;
}

// =========================================================
// member functions
// =========================================================

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl
		<< "ClapTrap name: "<< ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, DiamondTrap const & dt)
{
	out << "DiamondTrap:" << std::endl
		<< "{" << std::endl
		<< "\tname: " << dt.getName() << std::endl
		<< "\thit points: " << dt.getHitPoints() << std::endl
		<< "\tenergy points: " << dt.getEnergyPoints() << std::endl
		<< "\tattack damage: " << dt.getAttackDamage() << std::endl
		<< "}" << std::endl;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:48:32 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/28 20:41:21 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// =========================================================
// constructors
// =========================================================

ClapTrap::ClapTrap( void ) : _name("noname_ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap[ " << getName() << " ] : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Constructor with name \"" << _name << "\" called" << std::endl;
}


ClapTrap::ClapTrap( ClapTrap const & copy)
{
	*this = copy;
	std::cout << "ClapTrap[ " << getName() << " ] : Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap[ " << getName() << " ] : Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

std::string		ClapTrap::getName() const
{
	return ( _name );
}

unsigned int	ClapTrap::getHitPoints() const
{
	return ( _hitPoints );
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return ( _energyPoints );
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return ( _attackDamage );
}

void	ClapTrap::setName( std::string const & name)
{
	_name = name;
}

void ClapTrap::setHitPoints( unsigned int hp )
{
	_hitPoints = hp;
}

void ClapTrap::setEnergyPoints(unsigned int ep)
{
	_energyPoints = ep;
}

void	ClapTrap::setAttackDamage( unsigned int damage )
{
	_attackDamage = damage;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

ClapTrap & ClapTrap::operator=( ClapTrap const & copy)
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

void	ClapTrap::attack(std::string const & target)
{
	if (getAttackDamage() <= 0)
		std::cout << "ClapTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getAttackDamage()
			<< " attack damage points" << std::endl;
	else if (getEnergyPoints() < 1)
		std::cout << "ClapTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getEnergyPoints()
			<< " energy points" << std::endl;
	else if (getHitPoints() <= 0)
		std::cout << "ClapTrap: " << getName() << " is not able to attack "
			<< target << ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	if (getAttackDamage() > 0 && getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks "
			<< target << ", causing " << getAttackDamage()
			<< " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "It has no sense to attack " << getName()
			<< " he has " << getHitPoints() << " hit points" << std::endl;
		return ;
	}
	if (getHitPoints() <= amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << "ClapTrap " << getName() << " takes "
		<< amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() < 1)
		std::cout << "ClapTrap: " << getName() << " is not able to repair itself"
			<< ", because he has " << getEnergyPoints()
			<< " energy points" << std::endl;
	else if (getHitPoints() <= 0)
		std::cout << "ClapTrap: " << getName() << " is not able to repair itself"
			<< ", because he has " << getHitPoints()
			<< " hit points" << std::endl;
	if (getHitPoints() > 0 && getEnergyPoints() > 0 )
	{
		setHitPoints(getHitPoints() + amount);
		std::cout << "ClapTrap " << getName() << " recovers "
			<< amount << " hit points!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, ClapTrap const & ct)
{
	out << "ClapTrap:" << std::endl
		<< "{" << std::endl
		<< "\tname: " << ct.getName() << std::endl
		<< "\thit points: " << ct.getHitPoints() << std::endl
		<< "\tenergy points: " << ct.getEnergyPoints() << std::endl
		<< "\tattack damage: " << ct.getAttackDamage() << std::endl
		<< "}" << std::endl;
	return (out);
}

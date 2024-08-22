/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:48:32 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/20 13:11:24 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// =========================================================
// constructors
// =========================================================

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}


ClapTrap::ClapTrap( ClapTrap const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
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
	if (getHitPoints() <= 0) return ;
	_hitPoints = hp;
}

void ClapTrap::setEnergyPoints(unsigned int ep)
{
	if (getEnergyPoints() <= 0) return ;
	_energyPoints = ep;
}

void	ClapTrap::setAttackDamage( unsigned int damage )
{
	if (damage < 0) return ;
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

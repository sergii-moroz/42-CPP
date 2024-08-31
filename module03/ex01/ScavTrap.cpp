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
	setGuardGate(true);
	std::cout << "ScavTrap[ " << getName() << " ] : has entered the Gate Keeper mode" << std::endl;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:22:51 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/02 13:49:55 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// =========================================================
// constructors
// =========================================================

Character::Character() : ICharacter(), _name("unnamed")
{
	std::cout << "Character: " << BLACK
		<< "Default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character: " << BLACK
		<< "Typed constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & copy)
{
	std::cout << "Character: " << BLACK
		<< "Copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Character::~Character()
{
	std::cout << "Character: " << BLACK
		<< "Destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Character &	Character::operator=(Character const & rhs)
{
	if (this == &rhs)
		std::cout << "Character: " << RED
			<< "There is no need to use assignment operator [lhs==rhs]"
			<< RESET << std::endl;
	else
	{
		std::cout << "Character: " << BLACK
			<< "Asignment operator called" << RESET << std::endl;
		_name = rhs.getName();
		for(int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (rhs._inventory[i])
				_inventory[i] = rhs._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

// =========================================================
// getter
// =========================================================

std::string const &	Character::getName() const
{
	return (_name);
}

// =========================================================
// member functions
// =========================================================

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Character [ " << getName()
				<< " ] : " << CYAN << "equips materia of type " << m->getType()
				<< " in slot [ " << i << " ]" << RESET << std::endl;
			return ;
		}
	}
	std::cout << "Character [ " << getName()
		<< " ] : "<< RED << "couldn't equip materia of type " << m->getType()
		<< ", because there are no free slots" << RESET << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (_inventory[idx] == NULL) return ;
	if (idx >= 0 && idx < 4)
	{
		std::cout << "Character [ " << getName()
				<< " ] : " << CYAN << "unequips materia of type " << _inventory[idx]->getType()
				<< " from slot [ " << idx << " ]" << RESET << std::endl;
		_inventory[idx] = NULL;
	}
	else
		std::cout << "Character [ " << getName()
		<< " ] : " << RED << "couldn't unequip, because index: " << idx
		<< " out of rage [0-3]" << RESET << std::endl;
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx >= 0 && idx < 4)
		if ( _inventory[idx])
			_inventory[idx]->use(target);
		else
			std::cout << "Character [ " << getName()
				<< " ] : " << RED << "doesn't do anything, because "
				<< " inventory[ " << idx << " ]: " << _inventory[idx]
				<< " is empty" << RESET << std::endl;
	else
		std::cout << "Character [ " << getName()
		<< " ] : " << RED << "doesn't do anything, because index: " << idx
		<< " out of rage [0-3] " << RESET << std::endl;
}

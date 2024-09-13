/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:22:51 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 21:38:00 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// =========================================================
// constructors
// =========================================================

Character::Character() : _name("unnamed")
{
	std::cout << "Character: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character: Typed constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & copy)
{
	std::cout << "Character: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;
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
		std::cout << "Character: There is no need to use assignment operator [lhs==rhs]" << std::endl;
	else
	{
		std::cout << "Character: Asignment operator called" << std::endl;
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
			std::cout << "Character: [ " << getName()
				<< " ] : equips materia of type " << m->getType()
				<< " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Character: [ " << getName()
		<< " ] : couldn't equip materia of type " << m->getType()
		<< ", because there are no free slots" << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		std::cout << "Character [ " << getName()
				<< " ] : unequips materia of type " << _inventory[idx]->getType()
				<< " from slot [ " << idx << " ]" << std::endl;
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter & target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Character [ " << getName()
		<< " ] : doesn't do anything, because index: " << idx
		<< " out of rage [0-3] or inventory[ " << idx << " ]: " << _inventory[idx]
		<< " is empty" << std::endl;
}

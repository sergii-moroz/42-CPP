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

Character::Character() : ICharacter(), _name("default name"), _idx(0)
{
	std::cout << "Character: Default constructor called" << std::endl;
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
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Character &	Character::operator=(Character const & ref)
{
	std::cout << "Character: Asignment operator called" << std::endl;
	_name = ref.getName();
	_idx = ref._idx;
	for(int i = 0; i < 4; i++)
		*(_inventory + i) = ref._inventory[i];
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

}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter & target)
{

}

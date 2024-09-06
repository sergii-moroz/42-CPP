/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 20:03:49 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// =========================================================
// constructor
// =========================================================

Dog::Dog() : Animal(), _brain(new Brain())
{
	setType("Dog");
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog( Dog const & copy ) : Animal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << "Dog: Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog: Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Dog &	Dog::operator=(Dog const & ref)
{
	std::cout << "Dog: Assignation operator called" << std::endl;
	setType(ref.getType());
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	Dog::makeSound() const
{
	std::cout << getType() << ": Woof-Woof" << std::endl;
}

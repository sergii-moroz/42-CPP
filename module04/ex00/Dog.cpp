/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 18:12:46 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// =========================================================
// constructor
// =========================================================

Dog::Dog() : Animal()
{
	setType("Dog");
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog( Dog const & copy ) : Animal(copy)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Dog::~Dog()
{
	std::cout << "Dog: Destructor called" << std::endl;
}

// =========================================================
// member's function
// =========================================================

void	Dog::makeSound() const
{
	std::cout << getType() << ": woof-woof" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Dog &	Dog::operator=( Dog const & ref )
{
	std::cout << "Dog: Assignation operator called" << std::endl;
	setType(ref.getType());
	return (*this);
}

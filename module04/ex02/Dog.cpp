/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/01 11:28:10 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// =========================================================
// constructor
// =========================================================

Dog::Dog() : AAnimal(), _brain(new Brain())
{
	setType("Dog");
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog( Dog const & copy ) : AAnimal(copy)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = copy;
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

Dog &	Dog::operator=(Dog const & rhs)
{
	if (this == &rhs)
		std::cout << "Dog: There is no need to use assignment operator [lhs==rhs]"
			<< std::endl;
	else
	{
		std::cout << "Dog: Assignation operator called" << std::endl;
		_brain = new Brain(*rhs._brain);
		setType(rhs.getType());
	}
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	Dog::makeSound() const
{
	std::cout << getType() << ": Woof-Woof" << std::endl;
}

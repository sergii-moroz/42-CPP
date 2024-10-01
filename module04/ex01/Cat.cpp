/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/01 10:40:16 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// =========================================================
// constructor
// =========================================================

Cat::Cat() : Animal(), _brain(new Brain())
{
	setType("Cat");
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat( Cat const & copy ) : Animal(copy)
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat: Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Cat &	Cat::operator=(Cat const & rhs)
{
	if (this == &rhs)
		std::cout << "Cat: There is no need to use assignment operator [lhs==rhs]"
			<< std::endl;
	else
	{
		std::cout << "Cat: Assignation operator called" << std::endl;
		_brain = new Brain(*rhs._brain);
		setType(rhs.getType());
	}
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	Cat::makeSound() const
{
	std::cout << getType() << ": Miu-miu" << std::endl;
}

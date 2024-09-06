/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 19:58:56 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// =========================================================
// constructor
// =========================================================

Cat::Cat() : AAnimal(), _brain(new Brain())
{
	setType("Cat");
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat( Cat const & copy ) : AAnimal(copy), _brain(new Brain(*copy._brain))
{
	std::cout << "Cat: Copy constructor called" << std::endl;
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

Cat &	Cat::operator=(Cat const & ref)
{
	std::cout << "Cat: Assignation operator called" << std::endl;
	setType(ref.getType());
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	Cat::makeSound() const
{
	std::cout << getType() << ": Miu-miu" << std::endl;
}

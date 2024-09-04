/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/04 08:27:36 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// =========================================================
// constructor
// =========================================================

Cat::Cat()
{
	setType("Cat");
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat( Cat const & copy )
{
	*this = copy;
	std::cout << "Cat: Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

Cat::~Cat()
{
	std::cout << "Cat: Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Cat &	Cat::operator=( Cat const & ref )
{
	std::cout << "Cat: Assignation operator called" << std::endl;
	setType( ref.getType() );
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	Cat::makeSound() const
{
	std::cout << getType() << ": Miu-miu" << std::endl;
}

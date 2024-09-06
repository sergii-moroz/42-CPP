/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:11:32 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 18:21:08 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// =========================================================
// constructors
// =========================================================

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & copy)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

std::string	WrongAnimal::getType() const
{
	return ( _type );
}

void	WrongAnimal::setType( std::string type )
{
	_type = type;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & copy)
{
	std::cout << "WrongAnimal: Assignation operator called" << std::endl;
	setType(copy.getType());
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	WrongAnimal::makeSound() const
{
	std::cout << getType() << ": makes Wrong sound" << std::endl;
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, WrongAnimal const & ref)
{
	out << "WrongAnimal type: " << ref.getType() << std::endl;
	return ( out );
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:11:32 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 18:08:30 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// =========================================================
// constructors
// =========================================================

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(Animal const & copy)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Animal::~Animal()
{
	std::cout << "Animal: Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

std::string	Animal::getType() const
{
	return (_type);
}

void	Animal::setType( std::string type )
{
	_type = type;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Animal &	Animal::operator=( Animal const & copy)
{
	std::cout << "Animal: Assignation operator called" << std::endl;
	setType(copy.getType());
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	Animal::makeSound() const
{
	std::cout << getType() << ": makes No sound" << std::endl;
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, Animal const & ref)
{
	out << "Animal type: " << ref.getType() << std::endl;
	return ( out );
}

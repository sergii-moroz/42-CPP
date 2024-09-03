/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:11:32 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/03 10:37:46 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// =========================================================
// constructors
// =========================================================

Animal::Animal()
{
	std::cout << "Animal: Default constructor called";
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal: Typed constructor called";
}

Animal::Animal( Animal const & copy)
{
	*this = copy;
	std::cout << "Animal: Copy constructor called";
}

// =========================================================
// destructor
// =========================================================

Animal::~Animal()
{
	std::cout << "Animal: Destructor called";
}

// =========================================================
// getters / setters
// =========================================================

std::string	Animal::getType() const
{
	return ( _type );
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
	setType( copy.getType() );
	return ( *this );
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, Animal const & ref)
{
	out << "Animal type: " << ref.getType() << std::endl;
	return ( out );
}

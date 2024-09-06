/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:11:32 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 19:53:37 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// =========================================================
// constructors
// =========================================================

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & copy)
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

std::string	AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::setType( std::string type )
{
	_type = type;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

AAnimal &	AAnimal::operator=( AAnimal const & copy)
{
	std::cout << "AAnimal: Assignation operator called" << std::endl;
	setType(copy.getType());
	return (*this);
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, AAnimal const & ref)
{
	out << "AAnimal type: " << ref.getType() << std::endl;
	return ( out );
}

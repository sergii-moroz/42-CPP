/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:43:34 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 15:03:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// =========================================================
// constructors
// =========================================================

AMateria::AMateria() : _type("AMateria")
{
	std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & copy)
{
	*this = copy;
	std::cout << "AMateria: Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

std::string const &	AMateria::getType() const
{
	return (_type);
}

void	AMateria::setType(std::string const & type)
{
	_type = type;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

AMateria &	AMateria::operator=(AMateria const & ref)
{
	std::cout << "AMateria: Assignment operator called" << std::endl;
	setType(ref.getType());
	return (*this);
}

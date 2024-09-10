/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:48:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 19:36:34 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// =========================================================
// constructors
// =========================================================

Ice::Ice() : AMateria()
{
	std::cout << "Ice: Default constructor called" << std::endl;
	setType("ice");
}

Ice::Ice(Ice const & copy)
{
	std::cout << "Ice: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Ice &	Ice::operator=(Ice const & ref)
{
	std::cout << "Ice: Asignemt operator called" << std::endl;
	setType(ref.getType());
	return (*this);
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone()
{
	return (new Ice());
}

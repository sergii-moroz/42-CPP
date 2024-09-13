/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:48:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/13 12:07:29 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// =========================================================
// constructors
// =========================================================

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(Ice const & copy) : AMateria(copy)
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

Ice &	Ice::operator=(Ice const & rhs)
{
	if (this == &rhs)
		std::cout << "Ice: There is no need to use assignment operator [lhs==rhs]" << std::endl;
	else
	{
		std::cout << "Ice: Assignemt operator called" << std::endl;
		setType(rhs.getType());
	}
	return (*this);
}

// =========================================================
// member functions
// =========================================================

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria	*Ice::clone()
{
	return (new Ice());
}

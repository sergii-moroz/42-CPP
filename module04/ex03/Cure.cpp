/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:44:57 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 20:10:18 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// =========================================================
// constructors
// =========================================================

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(Cure const & copy): AMateria(copy)
{
	std::cout << "Cure: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Cure &	Cure::operator=(Cure const & rhs)
{
	if (this == &rhs)
		std::cout << "Cure: There is no need to use assignment operator [lhs==rhs]" << std::endl;
	else
	{
		std::cout << "Cure: Assignment operator called" << std::endl;
		setType(rhs.getType());
	}
	return (*this);
}

// =========================================================
// member functions
// =========================================================

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria	*Cure::clone()
{
	return (new Cure());
}

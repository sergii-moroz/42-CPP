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

Cure::Cure() : AMateria()
{
	std::cout << "Cure: Default constructor called" << std::endl;
	setType("cure");
}

Cure::Cure(Cure const & copy)
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

Cure &	Cure::operator=(Cure const & ref)
{
	std::cout << "Cure: Assignment operator called" << std::endl;
	setType(ref.getType());
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

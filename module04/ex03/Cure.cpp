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
	std::cout << "Cure: " << BLACK
		<< "Default constructor called" << RESET << std::endl;
}

Cure::Cure(Cure const & copy): AMateria(copy)
{
	std::cout << "Cure: " << BLACK
		<< "Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Cure::~Cure()
{
	std::cout << "Cure: " << BLACK
		<< "Destructor called" << RESET << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

Cure &	Cure::operator=(Cure const & rhs)
{
	if (this == &rhs)
		std::cout << "Cure: " << RED
			<< "There is no need to use assignment operator [lhs==rhs]"
			<< RESET << std::endl;
	else
	{
		std::cout << "Cure: " << BLACK
			<< "Assignment operator called" << RESET << std::endl;
		setType(rhs.getType());
	}
	return (*this);
}

// =========================================================
// member functions
// =========================================================

void	Cure::use(ICharacter & target)
{
	std::cout << CYAN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}

AMateria	*Cure::clone()
{
	return (new Cure());
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:48:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 15:01:25 by smoroz           ###   ########.fr       */
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


void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}

AMateria	*Ice::clone()
{
	return (new Ice());
}

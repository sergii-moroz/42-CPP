/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:20:05 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 13:20:19 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

// =========================================================
// constructors
// =========================================================

ICharacter::ICharacter()
{
	std::cout << "ICharacter: Default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const & copy)
{
	std::cout << "ICharacter: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

ICharacter::~ICharacter()
{
	std::cout << "ICharacter: Default destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

ICharacter &	ICharacter::operator=(ICharacter const & rhs)
{
	(void)rhs;
	return (*this);
}

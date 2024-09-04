/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/04 09:26:18 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// =========================================================
// constructor
// =========================================================

WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & copy )
{
	*this = copy;
	std::cout << "WrongCat: Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

WrongCat &	WrongCat::operator=( WrongCat const & ref )
{
	std::cout << "WrongCat: Assignation operator called" << std::endl;
	setType( ref.getType() );
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	WrongCat::makeSound() const
{
	std::cout << getType() << ": Muuuh" << std::endl;
}

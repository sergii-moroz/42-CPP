/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:53 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 18:24:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// =========================================================
// constructor
// =========================================================

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat: default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const & copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = copy;
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
	setType(ref.getType());
	return (*this);
}

// =========================================================
// member's function
// =========================================================

void	WrongCat::makeSound() const
{
	std::cout << getType() << ": Muuuh" << std::endl;
}

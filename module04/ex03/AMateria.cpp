/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:43:34 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/12 20:15:14 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// =========================================================
// constructors
// =========================================================

AMateria::AMateria() : _type("AMateria")
{
	std::cout << BLACK << "AMateria: Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << BLACK << "AMateria: Typed constructor called" << RESET << std::endl;
}

AMateria::AMateria(AMateria const & copy)
{
	std::cout << BLACK << "AMateria: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

AMateria::~AMateria()
{
	std::cout << BLACK << "AMateria: Destructor called" << RESET << std::endl;
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

AMateria &	AMateria::operator=(AMateria const & rhs)
{
	if (this == &rhs)
	{
		std::cout << BLACK << "AMateria: There is no need to use assignment operator [lhs==rhs]" << RESET << std::endl;
		return (*this);
	}
	std::cout << BLACK << "AMateria: Assignment operator called" << RESET << std::endl;
	setType(rhs.getType());
	return (*this);
}

// =========================================================
// member function
// =========================================================

AMateria	*AMateria::clone()
{
	return (this);
}

void	AMateria::use(ICharacter & target)
{
	std::cout << BLACK << "AMateria: use function called for target: "
		<< target.getName() << RESET << std::endl;
}

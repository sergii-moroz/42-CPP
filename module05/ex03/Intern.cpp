/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:36:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/27 14:42:54 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// =========================================================
// constructors
// =========================================================

Intern::Intern()
{
	std::cout << BLACK << "Intern: Default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const & copy)
{
	std::cout << BLACK << "Intern: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Intern::~Intern()
{
	std::cout << BLACK << "Intern: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Intern &	Intern::operator=(Intern const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "Intern: no need to use assignment operator(=)"
			<< RESET << std::endl;
	else
	{
		std::cout << BLACK << "Intern: Assignation operator called"
			<< RESET << std::endl;
	}
	return (*this);
}

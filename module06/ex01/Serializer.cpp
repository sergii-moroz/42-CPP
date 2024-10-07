/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:03:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 18:01:36 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// =========================================================
// constructors
// =========================================================

Serializer::Serializer()
{
	std::cout << BLACK << "Serializer: Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(Serializer const & copy)
{
	std::cout << BLACK << "Serializer: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Serializer::~Serializer()
{
	std::cout << BLACK << "Serializer: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Serializer &	Serializer::operator=(Serializer const & rhs)
{
	if (this != &rhs)
	{
		std::cout << BLACK << "Serializer: Assignment operator called" << RESET << std::endl;
		// nothing to copy
	}
	else
		std::cout << BLACK << "Serializer: no needs to use assignment operator" << RESET << std::endl;
	return (*this);
}

// =========================================================
// member function
// =========================================================

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t *raw)
{
	return(reinterpret_cast<Data *>(raw));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMaterialSource.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:20:05 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 13:20:19 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

// =========================================================
// constructors
// =========================================================

IMateriaSource::IMateriaSource()
{
	std::cout << BLACK << "IMateriaSource: Default constructor called" << RESET << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const & copy)
{
	std::cout << BLACK << "IMateriaSource: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

IMateriaSource::~IMateriaSource()
{
	std::cout << BLACK << "IMateriaSource: Default destructor called" << RESET << std::endl;
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

IMateriaSource &	IMateriaSource::operator=(IMateriaSource const & rhs)
{
	std::cout << BLACK << "IMateriaSource: There is no need to use assignment operator [lhs==rhs]" << RESET << std::endl;
	(void)rhs;
	return (*this);
}

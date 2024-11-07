/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:40:39 by smoroz            #+#    #+#             */
/*   Updated: 2024/11/07 14:40:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ==========================================
// Constructors
// ==========================================

RPN::RPN()
{
	std::cout << "RPN: Default constructor called" << std::endl;
}

RPN::RPN(RPN const & copy)
{
	std::cout << "RPN: Copy constructor called" << std::endl;
	*this = copy;
}

// ==========================================
// Destructor
// ==========================================

RPN::~RPN()
{
	std::cout << "RPN: Destructor called" << std::endl;
}

// ==========================================
// Assignment operator(=)
// ==========================================

RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
	{
		// nothing to do
	}
	return (*this);
}

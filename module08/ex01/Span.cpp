/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:13:23 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/14 20:13:23 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// =========================================================
// constructors
// =========================================================

Span::Span(): _n(0)
{
	std::cout << "Span: Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
	std::cout << "Span: N-constructor called (n=" << n << ")" << std::endl;
}

Span::Span(Span const & copy)
{
	std::cout << "Span: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Span::~Span()
{
	std::cout << "Span: Destructor called" << std::endl;
}

// =========================================================
// assignment operator overloading
// =========================================================

Span &	Span::operator=(Span const & rhs)
{
	std::cout << "Span: Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return (*this);
}



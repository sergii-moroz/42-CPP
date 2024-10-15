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
	// for (int i=0; i<n; i++)
	// 	_span[i] = nullptr;
}

Span::Span(Span const & copy)
{
	std::cout << "Span: Copy constructor called" << std::endl;
	*this = copy;
}

Span &	Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		// if (_span != nullptr)
		// 	delete [] _span;
		// _span = new int[_n];
		// for (int i=0; i<_n; i++)
		// 	_span[i] = rhs._span[i];
	}
	return (*this);
}

// =========================================================
// destructor
// =========================================================

Span::~Span()
{
	std::cout << "Span: Destructor called" << std::endl;
}

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

// =========================================================
// memberfunctions
// =========================================================

void	Span::addNumber(int val)
{
	std::cout << "Span: addNumber() called" << std::endl;
	if (_v.size() >= _n)
		throw ContainerHasNoFeeSpaceException();
	_v.push_back(val);
	std::cout << "Value: " << val << " is added to the container" << std::endl;
}

int		Span::shortestSpan(void)
{
	// std::cout << "Span: shortestSpan() called" << std::endl;
	if (_v.size() <= 1)
		throw ContainerHasNotEnoughMembersException();
	// Make a copy of _v
	std::vector<int> tmp = _v;
	// Sort it
	std::sort(tmp.begin(), tmp.end());
	// Define iterator
	std::vector<int>::iterator	it = tmp.begin();
	// Calculate span between first two elements
	int	minSpan = std::abs(*it - *(it + 1));
	for (std::vector<int>::iterator	it = tmp.begin() + 1; it < tmp.end() - 1; it++)
	{
		if (std::abs(*it - *(it + 1)) < minSpan)
			minSpan = std::abs(*it - *(it + 1));
	}
	return (minSpan);
}

int		Span::longestSpan(void)
{
	// std::cout << "Span: longestSpan() called" << std::endl;
	if (_v.size() <= 1)
		throw ContainerHasNotEnoughMembersException();
	return (*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}

// =========================================================
// exceptions
// =========================================================

const char *Span::ContainerHasNoFeeSpaceException::what(void) const throw()
{
	return("ERROR: Container has no free space to save one more value");
}

const char *Span::ContainerHasNotEnoughMembersException::what(void) const throw()
{
	return ("ERROR: Container has not enough members to perform this operation");
}

std::ostream &	operator<<(std::ostream & out, Span const & ref)
{
	if (ref._v.size() == 0)
		out << "{ empty }";
	else
	{
		out << "{ ";
		for (unsigned long i=0; i<ref._v.size(); i++)
			out << ref._v[i] << ", ";
		out << " }";
	}
	return (out);
}

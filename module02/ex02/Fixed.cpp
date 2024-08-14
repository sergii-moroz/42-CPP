/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:45:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/14 20:33:59 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const Fixed::_bits = 8;

// =========================================================
// constructors
// =========================================================

Fixed::Fixed() : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & nbr )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = nbr;
}

Fixed::Fixed( int const & nbr )
{
	// std::cout << "Int contructor called" << std::endl;
	setRawBits(nbr << Fixed::_bits);
}

Fixed::Fixed( float const & nbr )
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits( std::roundf(nbr * ( 1 << Fixed::_bits)) );
}

// =========================================================
// destructor
// =========================================================

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// =========================================================
// getters / setters
// =========================================================

int	Fixed::getRawBits( void ) const
{
	return ( _rawBits );
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

// =========================================================
// member functions
// =========================================================

float	Fixed::toFloat( void ) const
{
	return ( (float)getRawBits() / (1 << Fixed::_bits) );
}

int	Fixed::toInt( void ) const
{
	return (getRawBits() >> Fixed::_bits);
}

// =========================================================
// comparison <, >, <=, >=, ==, != operator's overloading
// =========================================================

bool	Fixed::operator<(Fixed const & nbr) const
{
	return ( toFloat() < nbr.toFloat() );
}

bool	Fixed::operator>(Fixed const & nbr) const
{
	return ( toFloat() > nbr.toFloat() );
}

bool	Fixed::operator<=(Fixed const & nbr) const
{
	return ( toFloat() <= nbr.toFloat() );
}

bool	Fixed::operator>=(Fixed const & nbr) const
{
	return ( toFloat() >= nbr.toFloat() );
}

bool	Fixed::operator==(Fixed const & nbr) const
{
	return ( toFloat() == nbr.toFloat() );
}

bool	Fixed::operator!=(Fixed const & nbr) const
{
	return ( toFloat() != nbr.toFloat() );
}

// =========================================================
// equal = operator's overloading
// =========================================================

Fixed &	Fixed::operator=( Fixed const & nbr )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(nbr.getRawBits());
	return (*this);
}

// =========================================================
// arithmetic *, -, *, / operator's overloading
// =========================================================

Fixed	Fixed::operator+(Fixed const & nbr)
{
	return ( Fixed( toFloat() + nbr.toFloat() ) );
}

Fixed	Fixed::operator-(Fixed const & nbr)
{
	return ( Fixed( toFloat() - nbr.toFloat() ) );
}

Fixed	Fixed::operator*(Fixed const & nbr)
{
	return ( Fixed( toFloat() * nbr.toFloat() ) );
}

Fixed	Fixed::operator/(Fixed const & nbr)
{
	return ( Fixed( toFloat() / nbr.toFloat() ) );
}

// =========================================================
// pre-increment, pre-decrement operator's overloading
// =========================================================

Fixed & Fixed::operator++( void )
{
	setRawBits( getRawBits() + 1 );
	return (*this);
}

Fixed & Fixed::operator--( void )
{
	setRawBits( getRawBits() - 1 );
	return ( *this );
}

// =========================================================
// post-increment, post-decrement operator's overloading
// =========================================================

Fixed Fixed::operator++( int )
{
	Fixed	temp(*this);

	setRawBits( getRawBits() + 1 );
	return ( temp );
}

Fixed Fixed::operator--( int )
{
	Fixed	temp(*this);

	setRawBits( getRawBits() - 1 );
	return ( temp );
}

// =========================================================
// static functions
// =========================================================

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, Fixed const & nbr )
{
	out << nbr.toFloat();
	return (out);
}

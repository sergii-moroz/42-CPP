/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:45:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/14 11:01:05 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const Fixed::_bits = 8;

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & nbr )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = nbr;
}

Fixed::Fixed( int const & nbr )
{
	std::cout << "Int contructor called" << std::endl;
	setRawBits(nbr << Fixed::_bits);
}

Fixed::Fixed( float const & nbr )
{
	// std::cout << "Float constructor called" << std::endl;
	setRawBits( std::roundf(nbr * ( 1 << Fixed::_bits)) );
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return ( _rawBits );
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

Fixed &	Fixed::operator=( Fixed const & nbr )
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(nbr.getRawBits());
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	return ( (float)getRawBits() / (1 << Fixed::_bits) );
}

int	Fixed::toInt( void ) const
{
	return (getRawBits() >> Fixed::_bits);
}

std::ostream &	operator<<(std::ostream & out, Fixed const & nbr )
{
	out << nbr.toFloat();
	return (out);
}

// ===== <, >, <=, >=, ==, != Operator's overloading =====

bool	Fixed::operator<(Fixed const & nbr)
{
	return ( toFloat() < nbr.toFloat() );
}

bool	Fixed::operator>(Fixed const & nbr)
{
	return ( toFloat() > nbr.toFloat() );
}

bool	Fixed::operator<=(Fixed const & nbr)
{
	return ( toFloat() <= nbr.toFloat() );
}

bool	Fixed::operator>=(Fixed const & nbr)
{
	return ( toFloat() >= nbr.toFloat() );
}

bool	Fixed::operator==(Fixed const & nbr)
{
	return ( toFloat() == nbr.toFloat() );
}

bool	Fixed::operator!=(Fixed const & nbr)
{
	return ( toFloat() != nbr.toFloat() );
}

// ===== +, -, *, / Operator's overloading =====

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

Fixed & Fixed::operator++( void )
{
	setRawBits( getRawBits() + (1 << Fixed::_bits) );
	return (*this);
}

Fixed & Fixed::operator--( void )
{
	setRawBits( getRawBits() - (1 << Fixed::_bits));
	return ( *this );
}

Fixed Fixed::operator++( int value )
{
	Fixed	temp(*this);
	value = 1;
	setRawBits( getRawBits() + (value << Fixed::_bits) );
	return ( temp );
}

Fixed Fixed::operator--( int value)
{
	Fixed	temp(*this);
	value = 1;
	setRawBits( getRawBits() - (value << Fixed::_bits));
	return ( temp );
}

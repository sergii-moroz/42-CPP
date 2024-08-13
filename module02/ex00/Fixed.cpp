/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:02:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/13 21:24:47 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	const Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & nbr )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = nbr;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
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

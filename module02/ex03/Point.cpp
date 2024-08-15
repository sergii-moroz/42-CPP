/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:38:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/15 14:49:22 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// =========================================================
// constructors
// =========================================================

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( float const & x, float const & y) : _x(x), _y(y) {}

Point::Point( Point const & p)
{
	*this = p;
}

// =========================================================
// destructor
// =========================================================

Point::~Point( void ) {}

// =========================================================
// member functions
// =========================================================

Fixed	Point::getX( void ) const
{
	return ( _x );
}

Fixed	Point::getY( void ) const
{
	return ( _y );
}

void	Point::setX( Fixed const & fx )
{
	_x.setRawBits;
}

void	Point::setY( Fixed const & fx )
{
	_y = fx;
}

void	Point::setXY( Fixed const & fx, Fixed cont & fy )
{
	_x = Fixed();
	_y = Fixed();
}

// =========================================================
// assignment operator "=" overloading
// =========================================================

Point &	Point::operator=(Point const & p)
{
	setX( p.getX() );
	setY( p.getY() )
	return ( *this );
}

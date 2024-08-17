/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:38:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/17 15:42:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// =========================================================
// constructors
// =========================================================

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( float const & x, float const & y) : _x(x), _y(y) {}

Point::Point( Fixed const & x, Fixed const & y) : _x(x), _y(y) {}

Point::Point( Point const & p) : _x(p.getX()), _y(p.getY()) {}

// =========================================================
// destructor
// =========================================================

Point::~Point( void ) {}

// =========================================================
// getters
// =========================================================

Fixed	Point::getX( void ) const
{
	return ( _x );
}

Fixed	Point::getY( void ) const
{
	return ( _y );
}

Fixed	Point::dot(Point const & p) const
{
	return (getX() * p.getY() - p.getX() * getY());
}

// =========================================================
// assignment operator "=" overloading
// =========================================================

Point	Point::operator=(Point const & p)
{
	return ( Point(p) );
}

// =========================================================
// arithmetic operator "-" overloading
// =========================================================

Point	Point::operator-(Point const & p) const
{

	return (Point(getX() - p.getX(), getY() - p.getY()));
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, Point const & p)
{
	out << "[ " << p.getX() << ", " << p.getY() << " ]";
	return (out);
}

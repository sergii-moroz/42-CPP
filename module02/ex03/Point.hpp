/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:30:34 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/17 15:43:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point( float const & x, float const & y );
		Point( Fixed const & x, Fixed const & y );
		Point( Point const & p);
		~Point();
		// member functions
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
		Fixed	dot(Point const & p) const;
		// overloading
		Point	operator=(Point const & p);
		Point	operator-(Point const & p) const;
};

std::ostream &	operator<<(std::ostream & out, Point const & p);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

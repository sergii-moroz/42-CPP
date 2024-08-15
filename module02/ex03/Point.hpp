/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:30:34 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/15 14:39:27 by smoroz           ###   ########.fr       */
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
		Point( Point const & p);
		~Point();
		// member functions
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
		void	setX( Fixed const & fx );
		void	setY( Fixed const & fx );
		void	setXY( Fixed const & fx, Fixed const & fy );
		// overloading
		Point &	operator=(Point const & p);

};

#endif

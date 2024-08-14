/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:46:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/14 07:54:25 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_bits;
	public:
		Fixed();
		Fixed( Fixed const & nbr );
		Fixed( int const & nbr );
		Fixed( float const & nbr );
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed &	operator=(Fixed const & nbr);
		bool	operator<(Fixed const & nbr);
		Fixed	operator*(Fixed const & nbr);

		Fixed & operator++( void );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &	operator<<(std::ostream & out, Fixed const & nbr);

#endif

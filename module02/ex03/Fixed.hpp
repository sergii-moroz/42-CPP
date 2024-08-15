/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:46:00 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/15 08:08:06 by smoroz           ###   ########.fr       */
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

		bool	operator<(Fixed const & nbr) const;
		bool	operator>(Fixed const & nbr) const;
		bool	operator==(Fixed const & nbr) const;
		bool	operator!=(Fixed const & nbr) const;
		bool	operator<=(Fixed const & nbr) const;
		bool	operator>=(Fixed const & nbr) const;

		Fixed	operator+(Fixed const & nbr) const;
		Fixed	operator-(Fixed const & nbr) const;
		Fixed	operator*(Fixed const & nbr) const;
		Fixed	operator/(Fixed const & nbr) const;

		Fixed & operator++( void );
		Fixed &	operator--( void );

		Fixed operator++( int );
		Fixed operator--( int );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed &	min(Fixed & a, Fixed & b);
		static Fixed &	max(Fixed & a, Fixed & b);
		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);
};

std::ostream &	operator<<(std::ostream & out, Fixed const & nbr);

#endif

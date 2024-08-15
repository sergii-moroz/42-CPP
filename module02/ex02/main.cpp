/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:46:41 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/14 20:42:16 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;


// Second test
/*
	Fixed		a( 4.8f );
	Fixed const	b( 1.5f );

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << std::endl;

	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "a = " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	Fixed c(13.7f);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "min(a, c): " << Fixed::min(a, c) << std::endl;
	std::cout << "min(a, c): " << Fixed::max(a, c) << std::endl;
	std::cout << "max(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
//*/

	return (0);
}

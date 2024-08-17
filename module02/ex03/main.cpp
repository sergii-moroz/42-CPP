/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:42:35 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/17 16:21:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	Point	a(0.0f,0.0f);
	Point	b(1.0f, 0.0f);
	Point	c(0.0f, 1.0f);
	Point	p(0.25f, 0.25f);

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "P: " << p << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:48:17 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/17 16:15:56 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	v1 = a - point;
	Point	v2 = b - point;
	Point	v3 = c - point;
	Fixed c1 = v1.dot(v2);
	Fixed c2 = v2.dot(v3);
	Fixed c3 = v3.dot(v1);

	std::cout << "v1: " << v1 << ", v2: " << v2 << ", v3: " << v3 << std::endl;
	std::cout << "c1: " << c1 << ", c2: " << c2 << ", c3: " << c3 << std::endl;
	return ((c1 < 0 && c2 < 0 && c3 < 0) || (c1 > 0 && c2 > 0 && c3 > 0));
}

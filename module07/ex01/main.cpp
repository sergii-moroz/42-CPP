/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:16:23 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/09 20:20:22 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

/*void	pow(int x)
{
	std::cout << "x: " << x << ", x*x: " << x*x << std::endl;
}

void	pow(float x)
{
	std::cout << "x: " << x << ", x*x: " << x*x << std::endl;
}*/

template <typename T>
void	pow(T x)
{
	std::cout << "x: " << x << ", x*x: " << x*x << std::endl;
}

int	main(void)
{
	int		intArr[] = {0, 1, 2, 3, 4};
	float	floatArr[] = {0.0f, 1.2f, 2.4f, 3.14f, 4.8f};
	double	doubleArr[] = {0.0, 1.6, 2.2, 3.1, 4.5};

	std::cout << std::endl << "Integer[]" << std::endl;
	::iter(intArr, 5, &pow);

	std::cout << std::endl << "Float[]" << std::endl;
	::iter(floatArr, 5, &pow);

	std::cout << std::endl << "Double[]" << std::endl;
	::iter(doubleArr, 5, &pow);
	return (0);
}

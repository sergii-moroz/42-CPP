/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:16:23 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/09 20:39:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void	pow(T x)
{
	std::cout << "x: " << x << ", x + x: " << x + x << std::endl;
}

int	main(void)
{
	int		intArr[] = {0, 1, 2, 3, 4};
	float	floatArr[] = {0.0f, 1.2f, 2.4f, 3.14f, 4.8f};
	double	doubleArr[] = {0.0, 1.6, 2.2, 3.1, 4.5};
	std::string	sArr[] = {"ab", "bc", "cd", "de"};

	std::cout << std::endl << "Integer[]" << std::endl;
	::iter(intArr, 5, &pow);

	std::cout << std::endl << "Float[]" << std::endl;
	::iter(floatArr, 5, &pow);

	std::cout << std::endl << "Double[]" << std::endl;
	::iter(doubleArr, 5, &pow);

	std::cout << std::endl << "std::string[]" << std::endl;
	::iter(sArr, 4, &pow);

	std::cout << std::endl << "Checking for empty array's pointer (nullptr)" << std::endl;
	int	*empty = nullptr;
	::iter(empty, 4, &pow);

	std::cout << std::endl << "Checking for empty function's pointer (nullptr)" << std::endl;
	void (*f)(int &) = nullptr;
	::iter(intArr, 5, f);

	return (0);
}

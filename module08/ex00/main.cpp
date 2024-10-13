/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:04:55 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 20:27:12 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

int	main(void)
{
	std::list<int>		l;
	std::vector<int>	v;

	l.push_back(5);
	l.push_back(13);
	l.push_back(42);

	v.push_back(34);
	v.push_back(72);
	v.push_back(-4);

	// std::list<int>::iterator it;

	try
	{
		std::cout << ::easyfind(l, 13) << std::endl;
		std::cout << ::easyfind(v, 13) << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

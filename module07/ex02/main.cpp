/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:50:07 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 11:30:15 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Array.hpp"

void	test(unsigned int id, std::string description)
{
	std::cout << std::endl;
	std::cout << MAGENTA << HR << HR << RESET << std::endl
		<< MAGENTA << "Test " << id << ": " << CYAN << description << RESET << std::endl
		<< MAGENTA << HR << HR << RESET << std::endl;
}

int	main(void)
{
	{
		::test(1, "Create empty array");
		Array<int>	iarr;
	}

	{
		::test(2, "Create empty array of size 4");
		Array<int>	iarr(4);
	}

	{
		::test(3, "Create empty array\n\tCreate another array with copy constructor");
		Array<int>	iarr;
		Array<int>	copy(iarr);
	}

	{
		::test(4, "Create empty array of size 4\n\tFill it with numbers");
		Array<int>	iarr(4);
		for (int i=0; i<4; i++)
			iarr[i] = i * 10 + i;
		iarr._debug();

		Array<int>	copy(iarr);
		copy._debug();
	}

	return (0);
}

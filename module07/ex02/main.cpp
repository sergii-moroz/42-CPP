/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:50:07 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 15:12:38 by smoroz           ###   ########.fr       */
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
		::test(4, "Create empty array of size 4\n\tFill it with numbers\n\tcopy this array to a new variable");
		Array<int>	iarr(4);
		for (int i=0; i<4; i++)
			iarr[i] = i * 10 + i;
		iarr._debug();

		Array<int>	copy(iarr);
		copy._debug();
	}

	{
		::test(5, "Create array A and array B and fill it with some numbers\n\tuse assignment operator(=) A = B\n\toriginal value of array A should be freed and then copied from B");
		Array<int>	a(4);
		Array<int>	b(4);
		for (int i=0; i<4; i++)
		{
			a[i] = i + 1;
			b[i] = i * 10 + i;
		}
		std::cout << "=== A ===" << std::endl;
		a._debug();
		std::cout << "=== B ===" << std::endl;
		b._debug();

		a = b;
		std::cout << "AFTER: a = b" << std::endl;
		std::cout << "=== A ===" << std::endl;
		a._debug();
		std::cout << "=== B ===" << std::endl;
		b._debug();
	}

	{
		::test(6, "Create empty array\n\t try to access index 0");
		Array<int>	a;
		try
		{
			std::cout << a[0] << std::endl;
		}
		catch(std::exception const & e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	{
		::test(7, "Create and fill array of size 4\n\t try to access index 4");
		Array<int>	a(4);
		for (int i=0; i<4; i++)
			a[i] = i * 10 + i;
		for (int i=0; i<5; i++)
		{
			try
			{
				std::cout << a[i] << std::endl;
			}
			catch(std::exception const & e)
			{
				std::cerr << RED << e.what() << RESET << std::endl;
			}
		}

	}

	return (0);
}

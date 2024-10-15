/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:28:56 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/14 20:28:56 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{

	{
		std::cout << "==========================================" << std::endl
		<< "Test 1: Create Span(5)" << std::endl
		<< "==========================================" << std::endl;
		Span	sp(5);
		std::cout << "Span: " << sp << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "==========================================" << std::endl
		<< "Test 2: Create Span(5) and Add values: 1, 3, 5" << std::endl
		<< "==========================================" << std::endl;
		Span	sp(5);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(5);
		std::cout << "Span: " << sp << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "==========================================" << std::endl
		<< "Test 3: Checking copy constructor && deep copy" << std::endl
		<< "==========================================" << std::endl;
		std::cout << " - step 1: Create span \"A\"" << std::endl;
		Span	a(5);
		std::cout << " - step 2: Add values to the span \"A\"" << std::endl;
		a.addNumber(1);
		a.addNumber(3);
		a.addNumber(5);
		std::cout << "Span a: " << a << std::endl;
		std::cout << " - step 3: Create span \"B\" through copy constructor" << std::endl;
		Span	b(a);
		std::cout << "Span b: " << b << std::endl;
		std::cout << " - step 4: Add one more value to the span \"A\" and span \"B\"" << std::endl;
		a.addNumber(10);
		b.addNumber(12);
		std::cout << "Span a: " << a << std::endl;
		std::cout << "Span b: " << b << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "==========================================" << std::endl
		<< "Test 4: Trying to add more elements then N" << std::endl
		<< "==========================================" << std::endl;
		Span	sp(3);
		for (int i=0; i<5; i++)
		{
			try
			{
				sp.addNumber(i);
			}
			catch (std::exception const & e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << sp << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "==========================================" << std::endl
		<< "Test 5: Checking longestSpan()" << std::endl
		<< "==========================================" << std::endl;
		std::cout << " - step 1: Create span" << std::endl;
		Span	a(5);
		std::cout << " - step 2: call logestSpan() with empty container" << std::endl;
		try
		{
			std::cout << "longestSpan: " << a.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << " - step 2: Add one value to the span and call longestSpan()" << std::endl;
		a.addNumber(1);
		try
		{
			std::cout << "longestSpan: " << a.longestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << " - step 4: Add three more value to the span and call longestSpan()" << std::endl;
		a.addNumber(8);
		a.addNumber(42);
		a.addNumber(13);
		std::cout << "Span: " << a << std::endl;
		try
		{
			std::cout << "longestSpan: " << a.longestSpan() << std::endl;
			std::cout << "shortestSpan: " << a.shortestSpan() << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}

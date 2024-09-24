/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:21:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/24 20:32:53 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << YELLOW << "=== Test 1: Create Bureaucrat ===" << std::endl;
	{
		Bureaucrat	b("bob", 2);
		std::cout << b << std::endl;
	}
	std::cout << YELLOW << "=== Test 1: END ===" << std::endl << std::endl;

	std::cout << YELLOW << "=== Test 2: Create Form ===" << std::endl;
	{
		Form	f("c25", 2, 1);
		std::cout << f << std::endl;
	}
	std::cout << YELLOW << "=== Test 2: END ===" << std::endl << std::endl;

	std::cout << YELLOW << "=== Test 3: if Bureaucrat [grade 2] could sign form that required grade 1 ===" << std::endl;
	{
		Bureaucrat	max("Max", 1);
		Bureaucrat	bob("Bob", 12);
		Form		f("a3", 6, 5);
		std::cout << max << std::endl;
		std::cout << bob << std::endl;
		std::cout << f << std::endl;
		std::cout << "Bob try to sign form" << std::endl;
		f.beSigned(bob);
		std::cout << "Max try to sign form" << std::endl;
		f.beSigned(max);
	}
	std::cout << YELLOW << "=== Test 3: END ===" << std::endl << std::endl;
	return (0);
}

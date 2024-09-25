/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:21:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 10:50:35 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
#include "Form.hpp"

void	testCreateForm(int grade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create Form with grade4Sign " << grade << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Form	f("c25", grade, 1);
		std::cout << f << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

void	testCreateForm2(int grade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create Form with grade4Exec " << grade << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Form	f("c25", 150, grade);
		std::cout << f << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

int	main(void)
{
	int	testId = 1;

	testCreateForm(-1, testId++);
	testCreateForm(1, testId++);
	testCreateForm(12, testId++);
	testCreateForm(150, testId++);
	testCreateForm(151, testId++);

	testCreateForm2(-1, testId++);
	testCreateForm2(1, testId++);
	testCreateForm2(12, testId++);
	testCreateForm2(150, testId++);
	testCreateForm2(151, testId++);

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

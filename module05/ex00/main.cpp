/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:05:38 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/18 15:16:16 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testCreateBureaucrat(int grade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create bureaucrat with grade " << grade << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	b("bob", grade);
		b.display();
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

void	testIncrementBureaucrat(int grade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Test increment" << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	b("bob", grade);
		b.display();
		b.incGrade();
		b.display();
		b.incGrade();
		b.display();
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

void	testDecrementBureaucrat(int grade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Test decrement" << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	b("bob", grade);
		b.display();
		b.decGrade();
		b.display();
		b.decGrade();
		b.display();
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

int	main(void)
{
	int	testId = 1;

	testCreateBureaucrat(-2, testId++);
	testCreateBureaucrat(1, testId++);
	testCreateBureaucrat(7, testId++);
	testCreateBureaucrat(255, testId++);
	testIncrementBureaucrat(2, testId++);
	testDecrementBureaucrat(149, testId++);
	return (0);
}

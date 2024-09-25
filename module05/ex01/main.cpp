/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:21:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 13:00:57 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	testSignForm(int formGrade, int bureaucratGrade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create Form with grade " << formGrade << std::endl
		<< CYAN << "Create Bureaucrat with grade " << bureaucratGrade << std::endl
		<< CYAN << "Bureaucrat try to sign Form " << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	max("Max", bureaucratGrade);
		Form	f("d3", formGrade, formGrade);
		max.display();
		std::cout << f << std::endl;

		f.beSigned(max);
		// Try to sign second time
		//f.beSigned(max);
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

	testSignForm(5, 12, testId++);
	testSignForm(12, 3, testId++);

	return (0);
}

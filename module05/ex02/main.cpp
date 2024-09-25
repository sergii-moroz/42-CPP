/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:21:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 19:38:47 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	testShrubberyCreationForm(std::string target, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create ShrubberyCreationForm with target " << target << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		std::cout << MAGENTA << "create ShrubberyForm as object" << RESET << std::endl;
		ShrubberyCreationForm	shr(target);
		ShrubberyCreationForm	*pShrubbery = NULL;
		std::cout << std::endl;

		std::cout << MAGENTA << "create ShrubberyForm as AForm *" << RESET << std::endl;
		AForm	*f = NULL;
		f = new ShrubberyCreationForm(target);
		std::cout << *f << std::endl;
		delete f;
		std::cout << std::endl;

		std::cout << MAGENTA << "create ShrubberyForm with copy constructor as ShrubberyCreationForm *" << RESET << std::endl;
		pShrubbery = new ShrubberyCreationForm(shr);
		std::cout << *pShrubbery << std::endl;
		delete pShrubbery;
		std::cout << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

/*void	testCreateForm2(int grade, int testId)
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
		AForm	f("c25", 150, grade);
		std::cout << f << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}//*/

void	testShrubberySignForm(int bureaucratGrade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create ShrubberyForm" << std::endl
		<< CYAN << "Create Bureaucrat with grade " << bureaucratGrade << std::endl
		<< CYAN << "Bureaucrat try to sign ShrubberyForm " << std::endl
		<< CYAN << "Bureaucrat try to execute ShrubberyForm " << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	max("Max", bureaucratGrade);
		max.display();
		AForm	*f = NULL;
		f = new ShrubberyCreationForm("home");
		std::cout << *f << std::endl;

		std::cout << BLACK << "try to sign" << RESET << std::endl;
		max.signForm(*f);
		std::cout << BLACK << "try to sign second time" << RESET << std::endl;
		max.signForm(*f);

		std::cout << BLACK << "try to execute" << RESET << std::endl;
		max.executeForm(*f);
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

int	main(void)
{
	int	testId = 1;

	testShrubberyCreationForm("home", testId++);
	testShrubberySignForm(45, testId++);
	testShrubberySignForm(137, testId++);
	testShrubberySignForm(145, testId++);
	testShrubberySignForm(150, testId++);
	/*testCreateForm(-1, testId++);
	testCreateForm(12, testId++);
	testCreateForm(150, testId++);
	testCreateForm(151, testId++);

	testCreateForm2(-1, testId++);
	testCreateForm2(1, testId++);
	testCreateForm2(12, testId++);
	testCreateForm2(150, testId++);
	testCreateForm2(151, testId++);

	testSignForm(5, 12, testId++);
	testSignForm(12, 3, testId++);*/

	return (0);
}

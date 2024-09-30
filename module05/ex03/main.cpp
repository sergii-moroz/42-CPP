/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:21:25 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/30 13:54:21 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

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

void	testRobotomyRequestForm(std::string target, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create RobotomyRequestForm with target " << target << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		std::cout << MAGENTA << "create RobotomyRequestForm as object" << RESET << std::endl;
		RobotomyRequestForm	rob(target);
		RobotomyRequestForm	*pRobotomy = NULL;
		std::cout << std::endl;

		std::cout << MAGENTA << "create RobotomyRequestForm as AForm *" << RESET << std::endl;
		AForm	*f = NULL;
		f = new RobotomyRequestForm(target);
		std::cout << *f << std::endl;
		delete f;
		std::cout << std::endl;

		std::cout << MAGENTA << "create RobotomyRequestForm with copy constructor as RobotomyRequestForm *" << RESET << std::endl;
		pRobotomy = new RobotomyRequestForm(rob);
		std::cout << *pRobotomy << std::endl;
		delete pRobotomy;
		std::cout << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

void	testPresidentialPardonForm(std::string target, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create PresidentialPardonForm with target " << target << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		std::cout << MAGENTA << "create PresidentialPardonForm as object" << RESET << std::endl;
		PresidentialPardonForm	rob(target);
		PresidentialPardonForm	*pPresidential = NULL;
		std::cout << std::endl;

		std::cout << MAGENTA << "create PresidentialPardonForm as AForm *" << RESET << std::endl;
		AForm	*f = NULL;
		f = new PresidentialPardonForm(target);
		std::cout << *f << std::endl;
		delete f;
		std::cout << std::endl;

		std::cout << MAGENTA << "create PresidentialPardonForm with copy constructor as PresidentialPardonForm *" << RESET << std::endl;
		pPresidential = new PresidentialPardonForm(rob);
		std::cout << *pPresidential << std::endl;
		delete pPresidential;
		std::cout << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

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

void	testRobotomySignForm(int bureaucratGrade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create RobotomyRequestForm" << std::endl
		<< CYAN << "Create Bureaucrat with grade " << bureaucratGrade << std::endl
		<< CYAN << "Bureaucrat try to sign RobotomyRequestForm " << std::endl
		<< CYAN << "Bureaucrat try to execute RobotomyRequestForm " << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	max("Max", bureaucratGrade);
		max.display();
		AForm	*f = NULL;
		f = new RobotomyRequestForm("home");
		std::cout << *f << std::endl;

		std::cout << BLACK << "try to sign" << RESET << std::endl;
		max.signForm(*f);
		std::cout << BLACK << "try to sign second time" << RESET << std::endl;
		max.signForm(*f);

		std::cout << BLACK << "try to execute" << RESET << std::endl;
		int maxTimes = 1;
		if (f->getIsSigned() && (max.getGrade() <= f->getGrade4Exec()))
			maxTimes = 10;
		for (int i = 0; i < maxTimes; i++)
		{
			std::cout << BLACK << std::endl << "[ " << i << " ] ======" << RESET << std::endl;
			max.executeForm(*f);
		}
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << "ERROR: " << e.what() << RESET <<std::endl;
	}
}

void	testPresidentialSignForm(int bureaucratGrade, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create PresidentialPardonForm" << std::endl
		<< CYAN << "Create Bureaucrat with grade " << bureaucratGrade << std::endl
		<< CYAN << "Bureaucrat try to sign PresidentialPardonForm " << std::endl
		<< CYAN << "Bureaucrat try to execute PresidentialPardonForm " << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Bureaucrat	max("Max", bureaucratGrade);
		max.display();
		AForm	*f = NULL;
		f = new PresidentialPardonForm("Bob");
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

void	testIntern(std::string form, std::string target, int testId)
{
	std::cout
		<< MAGENTA << std::endl
		<< "==========================================" << std::endl
		<< "Test " << testId << " : "
		<< CYAN << "Create Intern" << std::endl
		<< CYAN << "Create Form " << form << " for target " << target << std::endl
		<< MAGENTA << "=========================================="
		<< RESET << std::endl;
	try
	{
		Intern	SomeRandomIntern;
		AForm	*rrf;
		rrf = SomeRandomIntern.makeForm(form, target);
		std::cout << *rrf << std::endl;
		delete rrf;
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

	testRobotomyRequestForm("robotomyHome", testId++);
	testRobotomySignForm(42, testId++);
	testRobotomySignForm(45, testId++);
	testRobotomySignForm(72, testId++);
	testRobotomySignForm(100, testId++);

	testPresidentialPardonForm("Bob", testId++);
	testPresidentialSignForm(1, testId++);
	testPresidentialSignForm(5, testId++);
	testPresidentialSignForm(25, testId++);
	testPresidentialSignForm(30, testId++);

	testIntern("robotomy request", "Bob", testId++);
	return (0);
}

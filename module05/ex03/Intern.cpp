/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:36:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/27 17:07:23 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// =========================================================
// constructors
// =========================================================

Intern::Intern()
{
	std::cout << BLACK << "Intern: Default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const & copy)
{
	std::cout << BLACK << "Intern: Copy constructor called" << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Intern::~Intern()
{
	std::cout << BLACK << "Intern: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Intern &	Intern::operator=(Intern const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "Intern: no need to use assignment operator(=)"
			<< RESET << std::endl;
	else
	{
		std::cout << BLACK << "Intern: Assignation operator called"
			<< RESET << std::endl;
	}
	return (*this);
}

// =========================================================
// member function
// =========================================================

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm	*f;
	int		type;
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (type = 0; type < 3; type++)
	{
		if (name.compare(names[type]) == 0)
			break;
	}

	switch (type){
		case 0:
			f = new ShrubberyCreationForm(target);
			std::cout << GREEN << "Intern creates Shrubbery Creation Form" << std::endl;
			break;
		case 1:
			f = new RobotomyRequestForm(target);
			std::cout << GREEN << "Intern creates Robotomy Request Form" << std::endl;
			break;
		case 2:
			f = new PresidentialPardonForm(target);
			std::cout << GREEN << "Intern creates Presidential Pardon Form" << std::endl;
			break;
		default:
			throw FormNotExistException();
	}
	return (f);
}

// =========================================================
// Exceptions
// =========================================================

const char* Intern::FormNotExistException::what() const throw()
{
	return ("Intern: Such form doesn't exit");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:36:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/30 14:39:49 by smoroz           ###   ########.fr       */
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

AForm*	Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*func[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(names[i]) == 0)
			return ((this->*func[i])(target));
	}
	throw FormNotExistException();
}

// =========================================================
// Exceptions
// =========================================================

const char* Intern::FormNotExistException::what() const throw()
{
	return ("Intern: Such form doesn't exist");
}

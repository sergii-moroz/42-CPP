/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:50:45 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/27 13:31:38 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// =========================================================
// constructors
// =========================================================

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyForm", 72, 45), _target("unknown")
{
	std::cout << BLACK << "RobotomyRequestForm[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : AForm(copy)
{
	std::cout << BLACK << "RobotomyRequestForm[ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyForm", 72, 45), _target(target)
{
	std::cout << BLACK << "RobotomyRequestForm[ " << getName()
		<< " ]: Target constructor called" << RESET << std::endl;
}

// =========================================================
// destructor
// =========================================================

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BLACK << "RobotomyRequestForm[ " << getName()
		<< " ]: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "RobotomyRequestForm [ " << getName()
			<< " ]: no need to use assignment operator(=)" << RESET << std::endl;
	else
	{
		std::cout << BLACK << "RobotomyRequestForm[ " << getName()
			<< " ]: Assignation operator called" << RESET << std::endl;
		setIsSigned(rhs.getIsSigned());
		setTarget(rhs.getTarget());
	}
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	_target = target;
}

// =========================================================
// member function
// =========================================================

void	RobotomyRequestForm::action() const
{
	std::cout << YELLOW << "...Drilling noise..." << RESET << std::endl;
	std::srand(clock());
	int	r = std::rand() / 2;
	if (r % 2)
		std::cout << GREEN << getTarget() << " was robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << "Sorry ... robotomy of " << getTarget() << " failed" << RESET << std::endl;
}

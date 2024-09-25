/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:50:45 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 16:11:36 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// =========================================================
// constructors
// =========================================================

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 145, 137), _target("unknown")
{
	std::cout << BLACK << "ShrubberyCreationForm[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm(copy)
{
	std::cout << BLACK << "ShrubberyCreationForm[ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("SCF", 145, 137), _target(target)
{
	std::cout << BLACK << "ShrubberyCreationForm[ " << getName()
		<< " ]: Target constructor called" << RESET << std::endl;
}

// =========================================================
// destructor
// =========================================================

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BLACK << "ShrubberyCreationForm[ " << getName()
		<< " ]: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << BLACK << "ShrubberyCreationForm[ " << getName()
		<< " ]: Assignation operator called" << RESET << std::endl;
	setIsSigned(rhs.getIsSigned());
	setTarget(rhs.getTarget());
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	_target = target;
}

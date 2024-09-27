/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:50:45 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/27 13:52:03 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// =========================================================
// constructors
// =========================================================

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialForm", 25, 5), _target("unknown")
{
	std::cout << BLACK << "PresidentialPardonForm[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : AForm(copy)
{
	std::cout << BLACK << "PresidentialPardonForm[ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialForm", 25, 5), _target(target)
{
	std::cout << BLACK << "PresidentialPardonForm[ " << getName()
		<< " ]: Target constructor called" << RESET << std::endl;
}

// =========================================================
// destructor
// =========================================================

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLACK << "PresidentialPardonForm[ " << getName()
		<< " ]: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "PresidentialPardonForm [ " << getName()
			<< " ]: no need to use assignment operator(=)" << RESET << std::endl;
	else
	{
		std::cout << BLACK << "PresidentialPardonForm[ " << getName()
			<< " ]: Assignation operator called" << RESET << std::endl;
		setIsSigned(rhs.getIsSigned());
		setTarget(rhs.getTarget());
	}
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	_target = target;
}

// =========================================================
// member function
// =========================================================

void	PresidentialPardonForm::action() const
{
	std::cout << GREEN << getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

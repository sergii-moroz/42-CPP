/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:56:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 17:17:35 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// =========================================================
// constructors
// =========================================================

AForm::AForm() : _name("unknown"), _isSigned(false), _grade4Sign(150), _grade4Exec(150)
{
	std::cout << BLACK << "AForm[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

AForm::AForm(AForm const & copy) : _name(getName()), _isSigned(copy.getIsSigned()), _grade4Sign(copy.getGrade4Sign()), _grade4Exec(copy.getGrade4Exec())
{
	std::cout << BLACK << "AForm[ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _grade4Sign(gradeSign), _grade4Exec(gradeExec)
{
	std::cout << BLACK << "AForm[ " << getName()
		<< " ]: Named constructor called" << RESET << std::endl;

	if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
}

// =========================================================
// destructor
// =========================================================

AForm::~AForm()
{
	std::cout << BLACK << "AForm[ " << getName()
		<< " ]: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

AForm &	AForm::operator=(AForm const & rhs)
{
	std::cout << BLACK << "AForm[ " << getName()
		<< " ]: Assignation operator called" << RESET << std::endl;
	setIsSigned(rhs.getIsSigned());
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGrade4Sign() const
{
	return (_grade4Sign);
}

int	AForm::getGrade4Exec() const
{
	return (_grade4Exec);
}

void	AForm::setIsSigned(bool status)
{
	_isSigned = status;
}


// =========================================================
// member function
// =========================================================

void	AForm::beSigned(Bureaucrat const & ref)
{
	if (getIsSigned())
		throw AForm::AlreadySignedException();
	if (getGrade4Sign() < ref.getGrade())
		throw AForm::GradeTooHighException();
	setIsSigned(true);
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::IsNotSignedException();
	if (getGrade4Exec() < executor.getGrade())
		throw AForm::GradeTooHighException();
	action();
}

void	AForm::action() const
{
	std::cout << YELLOW << "AForm has not action" << RESET << std::endl;
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, AForm const & ref)
{
	out << MAGENTA << "AForm { " << BLACK << "name: \"" << RESET << ref.getName()
		<< BLACK << "\", isSigned: " << RESET << ref.getIsSigned()
		<< BLACK << ", grade4Sign: " << RESET << ref.getGrade4Sign()
		<< BLACK << ", grade4Exec: " << RESET << ref.getGrade4Exec()
		<< MAGENTA << " }" RESET;
	return (out);
}

// =========================================================
// Exceptions
// =========================================================

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm's Grade Too High!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("AForm's Grade Too Low!");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("AForm is already signed!");
}

const char* AForm::IsNotSignedException::what() const throw()
{
	return ("AForm is not signed!");
}

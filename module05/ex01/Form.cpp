/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:56:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 15:11:34 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// =========================================================
// constructors
// =========================================================

Form::Form() : _name("unknown"), _isSigned(false), _grade4Sign(150), _grade4Exec(150)
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

Form::Form(Form const & copy) : _name(copy.getName()), _isSigned(copy.getIsSigned()), _grade4Sign(copy.getGrade4Sign()), _grade4Exec(copy.getGrade4Exec())
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
	// *this = copy;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _grade4Sign(gradeSign), _grade4Exec(gradeExec)
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Named constructor called" << RESET << std::endl;

	if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
}

// =========================================================
// destructor
// =========================================================

Form::~Form()
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Form &	Form::operator=(Form const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "Form [ " << getName()
			<< " ]: no need to use assignment operator(=)" << RESET << std::endl;
	else
	{
		std::cout << BLACK << "Form[ " << getName()
			<< " ]: Assignation operator called" << RESET << std::endl;
		setIsSigned(rhs.getIsSigned());
	}
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGrade4Sign() const
{
	return (_grade4Sign);
}

int	Form::getGrade4Exec() const
{
	return (_grade4Exec);
}

void	Form::setIsSigned(bool status)
{
	_isSigned = status;
}


// =========================================================
// member function
// =========================================================

void	Form::beSigned(Bureaucrat const & ref)
{
	if (getIsSigned())
		throw Form::AlreadySignedException();
	if (getGrade4Sign() < ref.getGrade())
		throw Form::GradeTooHighException();
	setIsSigned(true);
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, Form const & ref)
{
	out << MAGENTA << "Form { " << BLACK << "name: \"" << RESET << ref.getName()
		<< BLACK << "\", isSigned: " << RESET << ref.getIsSigned()
		<< BLACK << ", grade4Sign: " << RESET << ref.getGrade4Sign()
		<< BLACK << ", grade4Exec: " << RESET << ref.getGrade4Exec()
		<< MAGENTA << " }" RESET;
	return (out);
}

// =========================================================
// Exceptions
// =========================================================

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form's Grade Too High!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form's Grade Too Low!");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}

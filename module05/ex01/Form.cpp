/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:56:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/24 20:35:21 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// =========================================================
// constructors
// =========================================================

Form::Form() : _name("unknown"), _isSigned(false), _grade4Sign(1), _grade4Exec(1)
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

Form::Form(Form const & copy) : _isSigned(copy.getIsSigned()), _grade4Sign(copy.getGrade4Sign()), _grade4Exec(copy.getGrade4Exec())
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _grade4Sign(gradeSign), _grade4Exec(gradeExec)
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Named constructor called" << RESET << std::endl;
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
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Assignation operator called" << RESET << std::endl;
	setIsSigned(rhs.getIsSigned());
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
	if (ref.getGrade() <= getGrade4Sign())
	{
		setIsSigned(true);
		ref.signForm(getIsSigned(), getName());
	}
	else
	{
		ref.signForm(getIsSigned(), getName());
		// Form::GradeTooLowException();
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:41 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 15:28:28 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// =========================================================
// constructors
// =========================================================

Bureaucrat::Bureaucrat()
{
	std::cout << BLACK << "Bureaucrat[ " << getName()
		<< " ]: Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << BLACK << "Bureaucrat [ " << getName()
		<< " ]: named constructor called" << RESET << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << BLACK << "Bureaucrat [ " << getName()
		<< " ]: Copy constructor called" << RESET << std::endl;
}

// =========================================================
// destructor
// =========================================================

Bureaucrat::~Bureaucrat()
{
	std::cout << BLACK << "Bureaucrat [ " << getName()
		<< " ]: destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "Bureaucrat [ " << getName()
			<< " ]: no need to use assignment operator(=)" << RESET << std::endl;
	else
	{
		std::cout << BLACK <<"Bureaucrat [ " << getName()
			<< " ]: Assignment operator called" << RESET << std::endl;
		_grade = rhs.getGrade();
	}
	return (*this);
}

// =========================================================
// getters / setters
// =========================================================

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// =========================================================
// member function
// =========================================================

void	Bureaucrat::incGrade(void)
{
	std::cout << BLACK << "Bureaucrat [ " << getName()
		<< " ] : grade's increment called" << RESET << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decGrade(void)
{
	std::cout << BLACK << "Bureaucrat [ " << getName()
		<< " ] : grade's decrement called" << RESET << std::endl;
	if (getGrade() == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::display(void) const
{
	std::cout << *this << std::endl;
}

void	Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << getName() << " signed \"" << form.getName()
				<< "\"" << RESET << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << RED << getName() << " couldn't sign " << form.getName()
				<< " because " << e.what() << RESET << std::endl;
	}
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b)
{
	out << b.getName() << ", bereaucrat grade " << b.getGrade();
	return (out);
}

// =========================================================
// Exceptions
// =========================================================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's Grade Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's Grade Too Low!");
}

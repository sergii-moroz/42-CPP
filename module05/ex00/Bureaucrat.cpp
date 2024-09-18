/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:41 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/18 13:13:25 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// =========================================================
// constructors
// =========================================================

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat[ " << getName()
		<< " ]: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat [ " << getName()
		<< " ]: named constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat [ " << getName()
		<< " ]: Copy constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat [ " << getName()
		<< " ]: destructor called" << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this == &rhs)
		std::cout << "Bureaucrat [ " << getName()
			<< " ]: no need to use assignment operator(=)" << std::endl;
	else
	{
		std::cout << "Bureaucrat [ " << getName()
			<< " ]: Assignment operator called" << std::endl;
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
	_grade--;
}

void	Bureaucrat::decGrade(void)
{
	_grade++;
}

void	Bureaucrat::display(void) const
{
	std::cout << *this << std::endl;
}

// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream & operator<<(std::ostream & out, Bureaucrat const & b)
{
	out << b.getName() << ", bereaucrat grade " << b.getGrade();
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:50:45 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 18:50:42 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// =========================================================
// constructors
// =========================================================

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), _target("unknown")
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

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyForm", 145, 137), _target(target)
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
	if (this == &rhs)
		std::cout << BLACK << "ShrubberyCreationForm [ " << getName()
			<< " ]: no need to use assignment operator(=)" << RESET << std::endl;
	else
	{
		std::cout << BLACK << "ShrubberyCreationForm[ " << getName()
			<< " ]: Assignation operator called" << RESET << std::endl;
		setIsSigned(rhs.getIsSigned());
		setTarget(rhs.getTarget());
	}
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

// =========================================================
// member function
// =========================================================

void	ShrubberyCreationForm::action() const
{
	std::string		outFileName;
	std::ofstream	outfile;

	outFileName = getTarget() + "_shrubbery";
	outfile.open(outFileName.c_str(), std::ios::out);
	if (outfile.is_open())
	{
		for (int i=0; i<3; i++)
			outfile << std::endl <<
				"       _-_" << std::endl <<
				"    /~~   ~~\\" << std::endl <<
				" /~~         ~~\\" << std::endl <<
				"{               }" << std::endl <<
				" \\  _-     -_  /" << std::endl <<
				"   ~  \\ //  ~" << std::endl <<
				"_- -   | | _- _" << std::endl <<
				"  _ -  | |   -_" << std::endl <<
				"      // \\\\" << std::endl;
		outfile.close();
	}
	else
		std::cerr << RED << "ERROR: Couldn't create file \""
			<< outFileName << "\"" << RESET << std::endl;
}

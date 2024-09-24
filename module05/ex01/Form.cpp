/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:56:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/24 16:05:11 by smoroz           ###   ########.fr       */
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

// =========================================================
// destructor
// =========================================================

Form::~Form()
{
	std::cout << BLACK << "Form[ " << getName()
		<< " ]: Destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:42:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 18:48:06 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <stdlib.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const &);
		RobotomyRequestForm &	operator=(RobotomyRequestForm const &);

		std::string	getTarget() const;
		void		setTarget(std::string);
		void		action() const;

	private:
		RobotomyRequestForm();
		std::string	_target;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:42:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/27 13:47:03 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <stdlib.h>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string const & target);
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm &	operator=(PresidentialPardonForm const &);

		std::string	getTarget() const;
		void		setTarget(std::string);
		void		action() const;

	private:
		PresidentialPardonForm();
		std::string	_target;
};

#endif

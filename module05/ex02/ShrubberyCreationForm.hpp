/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:42:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 18:48:06 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const &);

		std::string	getTarget() const;
		void		setTarget(std::string);
		void		action() const;

	private:
		ShrubberyCreationForm();
		std::string	_target;
};

#endif

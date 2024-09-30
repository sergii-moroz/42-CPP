/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:26:18 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/30 14:29:34 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

// # include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const & copy);
		~Intern();
		Intern &	operator=(Intern const & copy);
		AForm*		makeForm(std::string name, std::string target);

		class FormNotExistException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		AForm*		makeShrubbery(std::string target);
		AForm*		makeRobotomy(std::string target);
		AForm*		makePresidential(std::string target);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:06:45 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 17:07:23 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat();
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &);
		Bureaucrat &	operator=(Bureaucrat const &);
		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incGrade(void);
		void			decGrade(void);
		void			display(void) const;
		void			signForm(AForm & form) const;
		void			executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream &, Bureaucrat const &);

#endif

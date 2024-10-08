/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:58:44 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/25 14:50:32 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

class Bureaucrat;

class Form {
	public:
		~Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(Form const & copy);
		Form &		operator=(Form const & rhs);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGrade4Sign() const;
		int			getGrade4Exec() const;

		void		setIsSigned(bool);

		void		beSigned(Bureaucrat const &);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		Form();
		const std::string	_name;
		bool				_isSigned;
		const	int			_grade4Sign;
		const	int			_grade4Exec;
};

std::ostream &	operator<<(std::ostream  & out, Form const & ref);

#endif

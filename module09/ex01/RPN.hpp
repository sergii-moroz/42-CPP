/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:38:29 by smoroz            #+#    #+#             */
/*   Updated: 2024/11/07 14:38:29 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <exception>

class RPN
{
	public:
		static double	calc(std::string const &);

		class TooLowOperandsExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		RPN();
		~RPN();
		RPN(RPN const &);
		RPN &	operator=(RPN const &);
		static bool	isMathOperator(char const & c);
		static double	add(double const &, double const &);
		static double	sub(double const &, double const &);
		static double	mlt(double const &, double const &);
		static double	div(double const &, double const &);
};

#endif

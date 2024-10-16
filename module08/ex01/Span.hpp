/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:07:59 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/14 20:07:59 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const & copy);
		~Span();

		Span &	operator=(Span const & rhs);
		void	addNumber(int val);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		int		spanSize(void) const;
		int		elementAt(unsigned int i) const;

		class ContainerHasNoFeeSpaceException : public std::exception
		{
			virtual const char *what(void) const throw();
		};

		class ContainerHasNotEnoughMembersException : public std::exception
		{
			virtual const char *what(void) const throw();
		};

		class IndexOutOfRangeException: public std::exception
		{
			virtual const char	*what(void) const throw();
		};

	private:
		std::vector<int>	_v;
		unsigned int		_n;

		Span();
};

std::ostream &	operator<<(std::ostream & out, Span const &);

#endif

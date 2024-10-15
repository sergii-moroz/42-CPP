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

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const & copy);
		~Span();

		Span &	operator=(Span const & rhs);

	private:
		unsigned int		_n;
		std::vector<int>	_v;

		Span();
};

#endif

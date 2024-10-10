/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:43:22 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 08:39:55 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &);
		~Array();

		Array &			operator=(Array const &);
		unsigned int &	operator[](unsigned int const &);
		unsigned int &	size(void);

		class IndexOutOfRange : public std::exception
		{
			public:
				virtual const char	*what() const throw()
		};

	private:
		T	*_array;
};

#endif

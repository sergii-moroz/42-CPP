/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:36:48 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/10 20:26:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class notFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("ERROR: not found exception");
		}
};

template <typename T>
typename T::iterator	easyfind(T & container, int needle)
{
	typename T::iterator	it;
	it = std::find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw notFoundException();
	return (it);
}

// # include "easyfind.tpp"

#endif

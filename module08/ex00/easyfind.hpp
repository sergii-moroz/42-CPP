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

# include <exception>

template <typename T>
T	easyfind(T const & container, int const & needle)
{
	T::iterator	it;
	it = find(container.begin(), container.end(), needle);
	if (it == container.end())
		throw notFoundException();
	return (*it);
}

class notFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("ERROR: not found exception");
		}
};

// # include "easyfind.tpp"

#endif

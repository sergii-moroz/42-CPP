/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:30 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/09 20:06:47 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T & param1, T & param2)
{
	T tmp;
	tmp = param1;
	param1 = param2;
	param2 = tmp;
}

template <typename T>
T const & max(T const & x, T const & y)
{
	return (x > y ? x : y);
}

template <typename T>
T const & min(T const & x, T const & y)
{
	return ( x < y ? x : y);
}

#endif

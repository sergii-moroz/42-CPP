/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:04:16 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/09 20:22:29 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename atype>
void	iter(atype *parray, int size, void (*f)(atype &))
{
	if (parray == nullptr || f == nullptr)
		return ;
	for (int i=0; i<size; i++)
		f(parray[i]);
}

#endif

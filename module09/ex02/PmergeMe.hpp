/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:57:50 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/26 13:57:50 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>

class PmergeMe
{
	public:
		~PmergeMe();
		static void	process(int size, char **arr);

	private:
		PmergeMe();
		PmergeMe(PmergeMe const &);
		PmergeMe &	operator=(PmergeMe const &);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:58:40 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/26 17:01:20 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ==========================================
// Constructors
// ==========================================

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe: Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	std::cout << "PmergeMe: copy constructor called" << std::endl;
	*this = copy;
}

// ==========================================
// Destructor
// ==========================================

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe: Destructor called" << std::endl;
}

// ==========================================
// Assignment operator (=)
// ==========================================

PmergeMe &	PmergeMe::operator=(PmergeMe const & rhs)
{
	std::cout << "PmergeMe: Assignment operator(=) called" << std::endl;
	if (this != &rhs)
	{
		// nothing
	}
	return (*this);
}

// ==========================================
// Static function
// ==========================================

void	PmergeMe::process(int size, char **arr)
{
	(void)size;
	(void)arr;
}

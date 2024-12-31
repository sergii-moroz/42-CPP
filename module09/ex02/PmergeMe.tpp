/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:47:26 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/31 16:47:26 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

template <typename T>
struct MyContainer;

template <typename U>
struct MyContainer<std::vector<U> > {
	typedef std::vector< std::vector<U> > NestedContainer;
};

template <typename U>
struct MyContainer< std::deque<U> > {
	typedef std::deque< std::deque<U> > NestedContainer;
};

template <typename T>
void	PmergeMe::pairwiseRangeSort(T & v, std::size_t & range)
{
	while (2 * range <= v.size())
	{
		for (typename T::iterator it = v.begin(); (it + 2 * range) <= v.end(); it += 2 * range)
		{
			if (*(it + 2 * range - 1) < *(it + range - 1))
				std::swap_ranges(it, it + range, it + range);
		}
		range *= 2;
	}
	// last valid range
	range /= 2;
}

template <typename T>
void	PmergeMe::fordJohnsonSort(T & v)
{
	// step 1: sort pairs (Forwart)
	std::size_t	range = 1;
	pairwiseRangeSort(v, range);

	// Step 2:
	while (range > 0)
	{
		processRange(v, range);
		range /= 2;
	}
}

template <typename T>
void	PmergeMe::processRange(T & v, std::size_t range)
{
	typedef typename MyContainer<T>::NestedContainer	NestedContainer;
	NestedContainer	a, b;
	T	rest;

	createABR(v, a, b, rest, range);
}

template <typename T, typename U>
void	PmergeMe::createABR(T const & v, U & a, U & b, T & rest, std::size_t range)
{
	std::size_t	i = 0;
	while (i < v.size() / range)
	{
		T	vi(v.begin() + i * range, v.begin() + (i + 1) * range);
		if (i % 2)
			a.push_back(vi);
		else
			b.push_back(vi);
		i++;
	}
	rest = T(v.begin() + i * range, v.end());
}

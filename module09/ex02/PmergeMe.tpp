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
				std::cout << "size a: " << a.size() << " size b: " << b.size() << std::endl; // DEGUG -> DEL
				// print_AB(a, b);			// DEGUG -> DEL
				std::cout << "rest: ";	// DEGUG -> DEL
				print_v(rest);			// DEGUG -> DEL
				std::cout << std::endl;	// DEGUG -> DEL
	T	ai(a.size() + 1);
	ai_init(ai);
				std::cout << "a_i:"; print_v(ai); std::cout << std::endl; // DEGUG -> DEL

	NestedContainer	main, pend;
	T	odd;
	ABRToMainPendOdd(a, b, main, pend, odd);
				print_dv(main, "main");	// DEGUG -> DEL
				print_dv(pend, "pend");	// DEGUG -> DEL
				std::cout << "odd: "; print_v(odd); std::cout << std::endl;	// DEGUG -> DEL

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

template <typename T>
void	PmergeMe::ai_init(T & v)
{
	std::size_t	i = 0;
	for (typename T::iterator it=v.begin(); it != v.end(); ++it)
	{
		*it = static_cast<int>(i);
		i++;
	}
}

template <typename T, typename U>
void	PmergeMe::ABRToMainPendOdd(U const & a, U const & b, U & main, U & pend, T & odd)
{
	main.assign(a.begin(), a.end());
	main.insert(main.begin(), b.begin(), b.begin() + 1);
	T	b_last = *(b.end() - 1);

	if (b.size() > a.size())
	{
		odd.assign(b_last.begin(), b_last.end());
		pend.assign(b.begin() + 1, b.end() - 1);
	}
	else
	{
		odd.clear();
		pend.assign(b.begin() + 1, b.end());
	}
}

// ==========
// DEBUG
// ==========

template <typename T>
void	PmergeMe::print_v(T const & v)
{
	std::cout << "[ ";
	for (typename T::const_iterator it=v.begin(); it!=v.end(); ++it)
		std::cout << *it << ", ";
	std::cout << " ]";
}

template <typename U>
void	PmergeMe::print_dv(U const & main, std::string const & s)
{
	std::cout << s << ": [ ";
	for (typename U::const_iterator it=main.begin(); it!=main.end(); ++it)
	{
		print_v(*it);
		std::cout << ", ";
	}
	std::cout << " ]" << std::endl;
}

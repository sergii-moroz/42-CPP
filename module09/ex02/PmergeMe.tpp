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

				std::cout << MAGENTA << " === RANGE: " << range << " ===" RESET << std::endl;
	createABR(v, a, b, rest, range);
				std::cout << "size a: " << a.size() << " size b: " << b.size() << std::endl; // DEBUG -> DEL
				print_AB(a, b);			// DEBUG -> DEL
				std::cout << "rest: ";	// DEBUG -> DEL
				print_v(rest);			// DEBUG -> DEL
				std::cout << std::endl;	// DEBUG -> DEL
	T	ai(a.size() + 1);
	ai_init(ai);
				std::cout << "a_i:"; print_v(ai); std::cout << std::endl; // DEBUG -> DEL

	NestedContainer	main, pend;
	T	odd;
	ABRToMainPendOdd(a, b, main, pend, odd);
				print_dv(main, "main");	// DEBUG -> DEL
				print_dv(pend, "pend");	// DEBUG -> DEL
				std::cout << "odd: "; print_v(odd); std::cout << std::endl;	// DEBUG -> DEL

	// !!! if pend have not enough elements to insert with Jacobsthal numbers !!!
	if (pend.size() == 1)
		insertSinglePend(main, pend, ai);
	else
		insertUsingJacobsthal(main, pend, ai);

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

template <typename T>
void	PmergeMe::ai_update(T & v, std::size_t n)
{
	for (typename T::iterator it=v.begin() + n; it!=v.end(); ++it)
		(*it)++;
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

template <typename T, typename U>
void	PmergeMe::insertSinglePend(	U & main, U & pend, T & ai )
{
						std::cout << "!!! pend have not enough elements to use Jacobsthal numbers for insertion !!!" << std::endl;
	for (typename U::iterator p = pend.begin(); p != pend.end(); p++)
	{
						std::cout << "I want to insert b2: ";
						print_v(*p);
						std::cout << " between 0 and " << *(ai.begin() + 2) - 1 << std::endl;
		std::size_t	idx = binarySearch(main, *((*p).end() - 1), 0, *(ai.begin() + 2) - 1);
						std::cout << "idx: " << idx << std::endl;
		ai_update(ai, idx);
						std::cout << "a_i:"; print_v(ai); std::cout << std::endl;
		main.insert(main.begin() + idx, p, p+1);
	}
}

template <typename U>
std::size_t	PmergeMe::binarySearch(U const & main, int val, int low, int high)
{
	if (high <= low)
		return (val > *(main[low].end() - 1) ? (low + 1) : low);
	std::size_t	mid = (low + high) / 2;
	if (val == *(main[mid].end() - 1))
		return mid + 1;
	 if (val > *(main[mid].end() - 1))
		return binarySearch(main, val, mid + 1, high);
	return binarySearch(main, val, low, mid - 1);
}

template <typename T, typename U>
void	PmergeMe::insertUsingJacobsthal(U & main, U & pend, T & ai )
{
	// use Jabocstal numbers to effective insert numbers
						std::cout << "!!! use Jabocstal numbers to effective insert numbers !!!" << std::endl;
	std::size_t	jn_curr, jn_prev, jn_delt, n = 3;
	while (jacobsthal(n) <= pend.size() + 1)
	{
		jn_curr = jacobsthal(n);
		jn_prev = jacobsthal(n - 1);
		jn_delt = jn_curr - jn_prev;
		std::cout << "n: " << n << " "
			<< "jn_curr: " << jn_curr << " "
			<< "jn_prev: " << jn_prev << " "
			<< "jn_delt: " << jn_delt << std::endl;

		// insert
		// typedef typename MyContainer<T>::NestedContainer	NestedContainer;
		for (std::size_t i=0; i < jn_delt; i++)
		{
			typename U::iterator p=pend.begin() + jn_curr - i - 2; // index in pend start from b2, b3, b4
						std::cout << "I want to insert b" << jn_curr - i << ": ";
						print_v(*p);
						std::cout << " between 0 and " << ai[jn_curr - i] - 1 << std::endl;
			std::size_t	idx = binarySearch(main, *((*p).end() - 1), 0, ai[jn_curr - i] - 1);
						std::cout << "idx: " << idx << std::endl;
			ai_update(ai, idx);
						std::cout << "ai:"; print_v(ai); std::cout << std::endl;
			main.insert(main.begin() + idx, p, p+1);
						print_dv(main, "main");
						print_dv(pend, "pend");
						// std::cout << "odd: "; print_v(odd); std::cout << std::endl;
		}
		n++;
	}
	insertRemainingPend(main, pend, ai, n-1);
}

template <typename T, typename U>
void	PmergeMe::insertRemainingPend(U & main, U & pend, T & ai, std::size_t n)
{
	// if number of element in pend was bigger than last Jacobstal number
	// and less than next Jacobsthal number
						std::cout << "!!! insert remaining elements after last Jacobsthal number !!!" << std::endl;
	std::size_t	jn_curr = jacobsthal(n);
						std::cout << "jn_curr: " << jn_curr << std::endl;
	for (std::size_t i=jn_curr; i<=pend.size(); i++)
	{
		typename U::iterator p=pend.begin() + i - 1;
		std::cout << "I want to insert b" << i+1 << ": ";
						print_v(*p);
						std::cout << " between 0 and " << ai[i+1] - 1 << std::endl;
		std::size_t	idx = binarySearch(main, *((*p).end() - 1), 0, ai[i + 1] - 1);
		main.insert(main.begin() + idx, p, p+1);
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

template <typename U>
void	PmergeMe::print_AB(U const & a, U const & b)
{
	typename U::const_iterator itb = b.begin();
	for (typename U::const_iterator ita=a.begin(); ita!=a.end(); ++ita)
	{
		std::cout << "b: ";
		print_v(*itb);
		std::cout << ", a: ";
		print_v(*ita);
		std::cout << std::endl;
	}
}

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
# include <cstdlib>
# include <limits>
# include <cerrno>
# include <vector>
# include <deque>
# include <ctime>
# include <list>

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

class PmergeMe
{
	public:
		~PmergeMe();
		static void	process(int size, char **arr);
		static bool	isValidInteger(char const *str, int & result);
		static std::string	trim(std::string const & s);

		class NotANumber : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotAllStringWasConsumed : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotPositiveNumber : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OutOfRange : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		PmergeMe();
		PmergeMe(PmergeMe const &);
		PmergeMe &		operator=(PmergeMe const &);

		static void		print(std::vector<int> const & v);
		static void		print(std::deque<int> const & l);
		static double	elapsedTime(std::time_t start, std::time_t end);
		static unsigned long long	jacobsthal(std::size_t n);

		template <typename T>
		static void	pairwiseRangeSort(T & v, std::size_t & range);

		template <typename T>
		static void	fordJohnsonSort(T & v);

		template <typename T, typename U>
		static void	createABR(T const & v, U & a, U & b, T & rest, std::size_t range);

		template <typename T>
		static void	processRange(T & v, std::size_t range);

		template <typename T>
		static void	ai_init(T & v);

		template <typename T>
		static void	ai_update(T & v, std::size_t n);

		template <typename T, typename U>
		static void	ABRToMainPendOdd(U const & a, U const & b, U & main, U & pend, T & odd);

		template <typename U>
		static std::size_t	binarySearch(U const & main, int val, int low, int high);

		template <typename T, typename U>
		static void	insertSinglePend(	U & main, U & pend, T & ai );

		template <typename T, typename U>
		static void	insertUsingJacobsthal(U & main, U & pend, T & ai );

		template <typename T, typename U>
		static void	insertRemainingPend(U & main, U & pend, T & ai, std::size_t n);

		template <typename T, typename U>
		static void	insertOddElements(U & main, T & odd);

		template <typename T, typename U>
		static T	mainRToV(U const & main, T const & rest);


		// DEBUG
		template <typename T>
		static void	print_v(T const & v);

		template <typename U>
		static void	print_dv(U const & main, std::string const & s);

		template <typename U>
		static void	print_AB(U const & a, U const & b);

};

#include "PmergeMe.tpp"

#endif

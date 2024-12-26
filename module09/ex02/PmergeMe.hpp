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
# include <list>

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
		PmergeMe &	operator=(PmergeMe const &);
};

#endif

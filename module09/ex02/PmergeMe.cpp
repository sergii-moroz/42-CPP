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
	std::vector<int>	vec;
	std::deque<int>		deq;
	int					value;
	for (int i=0; i<size; i++)
	{
		std::string	s = trim(arr[i]);
		if (isValidInteger(s.c_str(), value))
		{
			vec.push_back(value);
			deq.push_back(value);
		}
	}

	PmergeMe::sortAndShowTime(vec, "vector");
	PmergeMe::sortAndShowTime(deq, "deque");
}

bool	PmergeMe::isValidInteger(char const *str, int & result)
{
	errno = 0;

	char	*endptr;
	long	value = std::strtol(str, &endptr, 10);

	if (str == endptr)
		throw NotANumber();

	if (*endptr != '\0')
		throw NotAllStringWasConsumed();

	if (errno == ERANGE ||value > std::numeric_limits<int>::max())
		throw OutOfRange();

	if (value < 0)
		throw NotPositiveNumber();

	result = static_cast<int>(value);
	return true;
}

std::string	PmergeMe::trim(std::string const & s)
{
	size_t	start = s.find_first_not_of("\f\n\r\t\v ");
	if (start == std::string::npos)
		return (s); // no content
	size_t	end	= s.find_last_not_of("\f\n\r\t\v ");
	size_t	range = end - start + 1;
	return (s.substr(start, range));
}

unsigned long long	PmergeMe::jacobsthal(std::size_t n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	unsigned long long prev2 = 0; // J(0)
	unsigned long long prev1 = 1; // J(1)
	unsigned long long current = 0;

	for (std::size_t i = 2; i <= n; ++i)
	{
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}

	return current;
}

// ==========================================
// Exceptions
// ==========================================

const char	*PmergeMe::NotANumber::what() const throw()
{
	return ("Error: Not a number!");
}

const char	*PmergeMe::NotAllStringWasConsumed::what() const throw()
{
	return ("Error: Not all string was consumed!");
}

const char	*PmergeMe::NotPositiveNumber::what() const throw()
{
	return ("Error: Not a positive number!");
}

const char	*PmergeMe::OutOfRange::what() const throw()
{
	return ("Error: Argument's value out of range!");
}

// ==========================================
// Time functions
// ==========================================

double	PmergeMe::elapsedTime(std::time_t start, std::time_t end)
{
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1.0e6);
}

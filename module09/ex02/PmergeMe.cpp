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
	std::list<int>		lst;
	int					value;
	for (int i=0; i<size; i++)
	{
		std::string	s = trim(arr[i]);
		if (isValidInteger(s.c_str(), value))
		{
			vec.push_back(value);
			lst.push_back(value);
		}
	}

	std::clock_t	start, end;
	std::cout << MAGENTA << "=== Vector ===" << RESET << std::endl;
	std::cout << "Before ";
	print(vec);
	std::cout << std::endl;
	start = std::clock();
	// Sorting algorithm here
	end = std::clock();
	std::cout << "After  ";
	print(vec);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector<int> : " << elapsedTime(start, end) << " us" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << MAGENTA << "=== List ===" << RESET << std::endl;
	std::cout << "Before ";
	print(lst);
	std::cout << std::endl;
	start = std::clock();
	// Sorting algorithm here
	end = std::clock();
	std::cout << "After  ";
	print(lst);
	std::cout << std::endl;
	std::cout << "Time to process a range of " << lst.size()
		<< " elements with std::list<int> : " << elapsedTime(start, end) << " us" << std::endl;
	std::cout << std::endl;
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
// Print functions
// ==========================================

void	PmergeMe::print(std::vector<int> const & v)
{
	for (std::vector<int>::const_iterator it=v.begin(); it!=v.end(); it++)
		std::cout << *it << " ";
}

void	PmergeMe::print(std::list<int> const & lst)
{
	for (std::list<int>::const_iterator it=lst.begin(); it!=lst.end(); it++)
		std::cout << *it << " ";
}

// ==========================================
// Time functions
// ==========================================

double	PmergeMe::elapsedTime(std::time_t start, std::time_t end)
{
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1.0e6);
}

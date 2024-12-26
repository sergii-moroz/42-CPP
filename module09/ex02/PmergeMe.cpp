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
	int	value;
	for (int i=0; i<size; i++)
	{
		std::string	s = trim(arr[i]);
		if (isValidInteger(s.c_str(), value))
		{
			vec.push_back(value);
			lst.push_back(value);
		}
	}

	// debug:
	// for (std::vector<int>::iterator it=vec.begin(); it!=vec.end(); it++)
	// 	std::cout << "i: " << " val: " << *it << std::endl;
	for (unsigned int i=0; i<vec.size(); i++)
		std::cout << "i: " << i << " val: " << vec[i] << std::endl;

	std::cout << "Vector:" << std::endl;
	std::cout << "List:" << std::endl;
}

bool	PmergeMe::isValidInteger(char const *str, int & result)
{
	char* endptr;
	errno = 0;

	long value = std::strtol(str, &endptr, 10);

	if (str == endptr)
		throw EmptyStringException();

	if (*endptr != '\0')
		return false;

	if (errno == ERANGE || value < 0 || value > std::numeric_limits<int>::max())
	{
		return false;
	}

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

const char	*PmergeMe::EmptyStringException::what() const throw()
{
	return ("Error: Argument couldn't be empty string!");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:50:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/09 11:58:59 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// =========================================================
// constructors
// =========================================================

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

// =========================================================
// destructor
// =========================================================

ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter: Destructor called" << std::endl;
}

// =========================================================
// Checking data
// =========================================================

bool	ScalarConverter::isChar(std::string s)
{
	std::string	str = ScalarConverter::trim(s);
	if (str.length() == 1 && isprint(str.at(0)) && !isdigit(str.at(0)))
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(std::string s)
{
	std::string	trimed = ScalarConverter::trim(s);
	if (ScalarConverter::isSpecial(trimed))
		return (false);
	std::istringstream	iss(trim(s));
	double	d;
	iss >> d;
	return (!iss.fail() && iss.eof());
}

bool	ScalarConverter::isFloat(std::string s)
{
	std::string	str = trim(s);
	int			n = str.length();
	if (n == 0)
		return (false);
	if (str.at(n - 1) != 'f')
		return (false);
	else
		str.resize(n - 1);
	return (isDouble(str));
}

bool	ScalarConverter::isInteger(std::string s)
{
	std::istringstream iss(trim(s));
	int	i;
	iss >> i;
	return (!iss.fail() && iss.eof());
}

bool	ScalarConverter::isSpecial(std::string s)
{
	return (!s.compare("nan") || !s.compare("nanf") ||
		!s.compare("+inf") || !s.compare("-inf") || !s.compare("inf") ||
		!s.compare("+inff") || !s.compare("-inff") || !s.compare("inff"));
}

// =========================================================
// Converting string
// =========================================================

char	ScalarConverter::strToChar(std::string const & s)
{
	std::string	str = ScalarConverter::trim(s);
	return (str.at(0));
}

double	ScalarConverter::strToDouble(std::string const & s)
{
	std::istringstream	iss(ScalarConverter::trim(s));
	double	d;
	iss >> d;
	return (d);
}

float	ScalarConverter::strToFloat(std::string const & s)
{
	std::string			str = ScalarConverter::trim(s);
	int					n = str.length();
	str.resize(n - 1);
	std::istringstream	iss(str);
	float	f;
	iss >> f;
	return (f);
}

int	ScalarConverter::strToInteger(std::string const & s)
{
	std::istringstream	iss(ScalarConverter::trim(s));
	int	i;
	iss >> i;
	return (i);
}

// =========================================================
// helper function
// =========================================================

std::string	ScalarConverter::trim(std::string const & s)
{
	size_t	start = s.find_first_not_of("\f\n\r\t\v ");
	if (start == std::string::npos)
		return (s); // no content
	size_t	end	= s.find_last_not_of("\f\n\r\t\v ");
	size_t	range = end - start + 1;
	return (s.substr(start, range));
}

// =========================================================
// Display data
// =========================================================

void	ScalarConverter::displayDouble(double val)
{
	// handle Char
	if (val >= 32 && val <= 126)
		std::cout << "char: \'" << static_cast<char>(val) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// handle Integer
	if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	else
		std::cout << "int: impossible (due overflow)" << std::endl;

	// handle Float
	if (val >= std::numeric_limits<float>::min() && val <= std::numeric_limits<float>::max())
		std::cout << std::fixed << std::setprecision(1)
			<< "float: " << static_cast<float>(val) << "f" << std::endl;
	else
		std::cout << "float: impossible (due overflow)" << std::endl;

	// handle Double
	std::cout << std::fixed << std::setprecision(1) << "double: " << val << std::endl;
}

void	ScalarConverter::displayFloat(float val)
{
	// handle Char
	if (val >= 32 && val <= 126)
		std::cout << "char: \'" << static_cast<char>(val) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// handle Integer
	if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	else
		std::cout << "int: impossible (due overflow)" << std::endl;

	// handle Float and Double
	std::cout << std::fixed << std::setprecision(1)
		<< "float: " << val << "f" << std::endl
		<< std::fixed << std::setprecision(1)
		<< "double: " << static_cast<double>(val) << std::endl;
}

void	ScalarConverter::displayInteger(int val)
{
	// handle Char
	if (val >= 32 && val <= 126)
		std::cout << "char: \'" << static_cast<char>(val) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// handle Integer, Float and Double
	std::cout << "int: " << val << std::endl
		<< std::fixed << std::setprecision(1)
		<< "float: " << static_cast<float>(val) << "f" << std::endl
		<< std::fixed << std::setprecision(1)
		<< "double: " << static_cast<double>(val) << std::endl;
}

void	ScalarConverter::displayChar(char val)
{
	// handle Char
	if (val >= 32 && val <= 126)
		std::cout << "char: \'" << val << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// handle Integer, Float and Double
	std::cout << "int: " << static_cast<int>(val) << std::endl
		<< std::fixed << std::setprecision(1)
		<< "float: " << static_cast<float>(val) << "f" << std::endl
		<< std::fixed << std::setprecision(1)
		<< "double: " << static_cast<double>(val) << std::endl;
}

void	ScalarConverter::displaySpecial(std::string const & s)
{
	std::string	str = trim(s);
	if (!str.compare("nan") || !str.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: nanf" << std::endl
			<< "double: nan" << std::endl;
	}
	else if (!str.compare("+inf") || !str.compare("+inff"))
	{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: +inff" << std::endl
			<< "double: +inf" << std::endl;
	}
	else if (!str.compare("-inf") || !str.compare("-inff"))
	{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: -inff" << std::endl
			<< "double: -inf" << std::endl;
	}
	else if (!str.compare("inf") || !str.compare("inff"))
	{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: inff" << std::endl
			<< "double: inf" << std::endl;
	}
}

void	ScalarConverter::displayImpossible(void)
{
	std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;
}

// =========================================================
// member function: converter()
// =========================================================

void	ScalarConverter::convert(std::string s)
{
	if (isChar(s))
	{
		char c = ScalarConverter::strToChar(s);
		displayChar(c);
	}
	else if (isInteger(s))
	{
		int	i = ScalarConverter::strToInteger(s);
		displayInteger(i);
	}
	else if (isFloat(s))
	{
		float	f = ScalarConverter::strToFloat(s);
		displayFloat(f);
	}
	else if (isDouble(s))
	{
		double d = ScalarConverter::strToDouble(s);
		displayDouble(d);
	}
	else if (isSpecial(s))
		displaySpecial(s);
	else
		displayImpossible();
}

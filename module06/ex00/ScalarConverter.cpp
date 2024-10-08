/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:50:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/02 20:21:57 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}

bool	ScalarConverter::isDouble(std::string s)
{
	std::istringstream	iss(trim(s));
	double	d;
	iss >> d;
	return (!iss.fail() && iss.eof());
}

bool	ScalarConverter::isFloat(std::string s)
{
	std::string	str = trim(s);
	int			n = str.length();
	if (str.at(n - 1) != 'f')
		return (false);
	else
		str.resize(n - 1);
	return (isDouble(str));
}

bool	ScalarConverter::isInteger(std::string s)
{
	int	i;
	std::istringstream iss(trim(s));
	iss >> i;
	return (!iss.fail() && iss.eof());
}

std::string	ScalarConverter::trim(std::string const & s)
{
	size_t	start = s.find_first_not_of("\f\n\r\t\v ");
	if (start == std::string::npos)
		return (s); // no content
	size_t	end	= s.find_last_not_of("\f\n\r\t\v ");
	size_t	range = end - start + 1;
	return (s.substr(start, range));
}

/*std::string	ScalarConverter::trimf(std::string const & s)
{
	std::string	str = trim(s);
	int			n = str.length();

	if (n == 0)
		return (str);
	if (str.at(n - 1) == 'f')
		str.resize(n - 1);
	return (str);*/
}

void	ScalarConverter::displayFromDouble(std::string const & s)
{
	std::cout << "char: " << displayChar(atoi(s.c_str())) << std::endl
		<< "int: " << static_cast<int>(atoi(s.c_str())) << std::endl
		<< std::fixed << std::setprecision(1)
		<< "float: " << static_cast<float>(atof(s.c_str())) << "f" << std::endl
		<< std::fixed << std::setprecision(1) << "double: "
		<< static_cast<double>(atof(s.c_str())) << std::endl;
}

std::string	ScalarConverter::displayChar(int c)
{
	std::string	s = "Non displayable";

	if (std::isprint(c))
		s = static_cast<char>(c);
	return (s);
}

std::string	ScalarConverter::displayInt(std::string s)
{
	std::string	resStr = s;
	int	intMax = std::numeric_limits<int>::max();
	int	intMin = std::numeric_limits<int>::min();

	if (isInteger(s))
	{
		double	d = atof(s.c_str());
		if (d > intMax)
			resStr = "nan";
		if (d < intMin)
			resStr = "-nan";
	}
	else
		resStr = "impossible";
	return (resStr);
}

void	ScalarConverter::convert(std::string s)
{
	std::cout << "ScalarConverter: convert method called" << std::endl;
	if (isDouble(s))
		displayFromDouble(s);
	/*else if (isInteger(s))
		displayFromInteger(s);
	else
		displayDefault(s);*/
	/*std::cout << "char: " << static_cast<char>(atoi(s.c_str())) << std::endl
		<< "int: " << static_cast<int>(atoi(s.c_str())) << std::endl;
	std::cout << std::fixed << std::setprecision(1)	<< "float: " << static_cast<float>(atof(s.c_str())) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(atof(s.c_str())) << std::endl
		<< "string: " << s << std::endl;*/
}
//	 	  42f
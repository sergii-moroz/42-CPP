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

void	ScalarConverter::convert(std::string s)
{
	std::cout << "ScalarConverter: convert method called" << std::endl;
	std::cout << "char: " << static_cast<char>(atoi(s.c_str())) << std::endl
		<< "int: " << static_cast<int>(atoi(s.c_str())) << std::endl;
	std::cout << std::fixed << std::setprecision(1)	<< "float: " << static_cast<float>(atof(s.c_str())) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(atof(s.c_str())) << std::endl
		<< "string: " << s << std::endl;
}

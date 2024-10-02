/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:50:06 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/02 16:08:34 by smoroz           ###   ########.fr       */
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
	std::cout << "char: " << "_charValueHere_" << std::endl
		<< "int: " << "_intValueHere_" << std::endl
		<< "float: " << "_floatValueHere_" << std::endl
		<< "double: " << "_doubleValueHere_" << std::endl
		<< "string: " << s << std::endl;
}

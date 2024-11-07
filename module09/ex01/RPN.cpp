/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:40:39 by smoroz            #+#    #+#             */
/*   Updated: 2024/11/07 14:40:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ==========================================
// Constructors
// ==========================================

RPN::RPN()
{
	std::cout << "RPN: Default constructor called" << std::endl;
}

RPN::RPN(RPN const & copy)
{
	std::cout << "RPN: Copy constructor called" << std::endl;
	*this = copy;
}

// ==========================================
// Destructor
// ==========================================

RPN::~RPN()
{
	std::cout << "RPN: Destructor called" << std::endl;
}

// ==========================================
// Assignment operator(=)
// ==========================================

RPN &	RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
	{
		// nothing to do
	}
	return (*this);
}

// ==========================================
//	member functions
// ==========================================

double	RPN::calc(std::string const & s)
{
	std::stack<double>	stack;

	char	c;
	for (size_t i=0; i < s.length(); i++)
	{
		c = s.at(i);
		if (std::isdigit(c))
			stack.push(static_cast<double>(c) - '0');
		else if (std::isspace(c))
			continue;
		else if (RPN::isMathOperator(c))
		{
			if (stack.size() < 2)
				throw TooLowOperandsExeption();
			double	y = stack.top();
			stack.pop();
			double	x = stack.top();
			stack.pop();
			switch(c)
			{
				case '+':
					// std::cout << "plus" << std::endl;
					stack.push(RPN::add(x, y));
					break;
				case '-':
					// std::cout << "minus" << std::endl;
					stack.push(RPN::sub(x, y));
					break;
				case '*':
					// std::cout << "multiplication" << std::endl;
					stack.push(RPN::mlt(x, y));
					break;
				case '/':
					// std::cout << "div" << std::endl;
					stack.push(RPN::div(x, y));
					break;
				default:
					std::cout << "error: unknown operator" << std::endl;

			}
		}
		else
			std::cout << "invalid character" << std::endl;
	}
		// std::cout << s.at(i) << std::endl;
	return (stack.top());
}

bool	RPN::isMathOperator(char const & c)
{
	std::string	ops = "+-*/";
	return (ops.find(c) != std::string::npos);
}

double	RPN::add(double const & x, double const & y)
{
	return (x + y);
}

double	RPN::sub(double const & x, double const & y)
{
	return (x - y);
}

double	RPN::mlt(double const & x, double const & y)
{
	return (x * y);
}

double	RPN::div(double const & x, double const & y)
{
	return (x / y);
}

const char	*RPN::TooLowOperandsExeption::what() const throw()
{
	return ("ERROR: Too low operand on the stack!");
}

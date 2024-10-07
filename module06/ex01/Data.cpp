/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:17:30 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 10:50:23 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// =========================================================
// constructors
// =========================================================

Data::Data()
{
	std::cout << BLACK << "Data: Default constructor called" << RESET << std::endl;
}

Data::Data(int count, double price, std::string name) : _count(count), _price(price), _name(name)
{
	std::cout << BLACK << "Data: Named constructor called" << RESET << std::endl;
}

Data::Data(Data const & copy)
{
	std::cout << BLACK << "Data: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

Data::~Data()
{
	std::cout << BLACK << "Data: Destructor called" << RESET << std::endl;
}

// =========================================================
// operator's overloading
// =========================================================

Data &	Data::operator=(Data const & rhs)
{
	if (this == &rhs)
		std::cout << BLACK << "Data: no need to use assignment operator(=)" << RESET << std::endl;
	else
	{
		std::cout << BLACK << "Data: Assignment operator called" << RESET << std::endl;
		setName(rhs.getName());
		setPrice(rhs.getPrice());
		setCount(rhs.getCount());
	}
	return (*this);
}


// =========================================================
// setter/getter
// =========================================================

std::string	Data::getName(void) const
{
	return (_name);
}

double	Data::getPrice(void) const
{
	return (_price);
}

int	Data::getCount(void) const
{
	return (_count);
}

void	Data::setName(std::string name)
{
	_name = name;
}

void	Data::setPrice(double price)
{
	_price = price;
}

void	Data::setCount(int count)
{
	_count = count;
}


// =========================================================
// std::ostream << operator's overloading
// =========================================================

std::ostream &	operator<<(std::ostream & out, Data const & data)
{
	out << "name: " << data.getName()
		<< ", price: " << data.getPrice()
		<< ", count: " << data.getCount();
	return (out);
}

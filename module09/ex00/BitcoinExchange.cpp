/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:22 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/19 15:38:40 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ==========================================
// Constructors
// ==========================================

BitcoinExchange::BitcoinExchange()
{
	std::cout << BLACK << "BitcoinExchange: Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	std::cout << BLACK << "BitcoinExchange: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// ==========================================
// Destructor
// ==========================================

BitcoinExchange::~BitcoinExchange()
{
	std::cout << BLACK << "BitcoinExchange: Destructor called" << RESET << std::endl;
}

// ==========================================
// Assignment operator(=)
// ==========================================
BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		// do something
	}
	return (*this);
}

// ==========================================
// Member functions
// ==========================================

void	BitcoinExchange::usage(void)
{
	std::cout
		<< RED << "[ERROR]"
		<< RESET << ": Wrong arguments' number" << std::endl
		<< "         usage: " << BLACK << "./btc <fileName>" << RESET << std::endl;
}

void	BitcoinExchange::loadDB(void)
{
	std::cout << BLACK << "BitcoinExchange: loadDB function called" << std::endl;

	std::fstream	infile;
	std::string		line;

	infile.open(BTC_DB, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenDBFileException();
	infile.close();
}

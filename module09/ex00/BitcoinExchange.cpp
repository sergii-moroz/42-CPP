/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:22 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/19 16:36:06 by smoroz           ###   ########.fr       */
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
	std::cout << BLACK << "BitcoinExchange: loadDB function called" << RESET << std::endl;

	std::fstream	infile;
	std::string		line;

	infile.open(BTC_DB, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenDBFileException();

	int		year, month, day;
	float	price;
	int		lineCounter = 0;
	while (std::getline(infile, line))
	{
		int	n = sscanf(line.c_str(), "%d-%d-%d,%f", &year, &month, &day, &price);
		if (n != 4)
		{
			std::cerr << std::endl;
			std::cerr << RED << "ERROR |" << WHITE << " Wrong format!" << RESET << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " expect 4 values (year-month-day,price), but got only "
				<< n << RESET << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
			lineCounter++;
			continue;
		}
		if (price < 0)
		{
			std::cerr << std::endl;
			std::cerr << RED << "ERROR |" << WHITE << " Price couldn't be negative!" << RESET << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
			lineCounter++;
			continue;
		}
		if (year < 0 || month < 0 || day < 0)
		{
			std::cerr << std::endl;
			std::cerr << "ERROR |" << WHITE << " Year||month||day couldn't be negative!" << RESET << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
			lineCounter++;
			continue;
		}

		std::tm	timeInfo = {};
		timeInfo.tm_year = year - 1900;
		timeInfo.tm_mon = month - 1;
		timeInfo.tm_mday = day;
		std::time_t	timestamp = std::mktime(&timeInfo);
		if (timestamp == -1)
		{
			std::cerr << std::endl;
			std::cerr << RED << "ERROR |" << WHITE << " time processing!" << RESET << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
			lineCounter++;
			continue;
		}

		std::cout << line << std::endl;
		std::cout << "timestamp: " << timestamp << std::endl;
		lineCounter++;
	}
	infile.close();
}

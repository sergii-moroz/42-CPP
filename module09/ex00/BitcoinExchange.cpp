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
		if (!isValidDate(timeInfo, year, month, day))
		{
			std::cerr << std::endl;
			std::cerr << RED << "ERROR |" << WHITE << " Wrong date value!" << RESET << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " date: " << CYAN << year << "-" << month << "-" << day
				<< BLACK << " was converted to -> " << YELLOW << timeInfo.tm_year + 1900 << "-" << timeInfo.tm_mon + 1 << "-"
				<< timeInfo.tm_mday << std::endl;
			std::cerr << RED << std::setw(7) << "|"
				<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
			lineCounter++;
			continue;
		}

		std::cout << line << std::endl;
		std::cout << "timestamp: " << timestamp << std::endl;
		db[timestamp] = price;
		lineCounter++;
	}
	infile.close();
	std::cout << "db size: " << db.size() << std::endl;
}

void	BitcoinExchange::evaluate(char *fileName)
{
	std::cout << BLACK << "BitcoinExchange: evaluate function called" << RESET << std::endl;

	std::fstream	infile;
	infile.open(fileName, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenDBFileException();

	std::string	line;
	int			lineCounter = 0;
	while (std::getline(infile, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		processLine(line, lineCounter);
		lineCounter++;
	}
	infile.close();
}

// ==========================================
// Helpers functions
// ==========================================

void	BitcoinExchange::processLine(std::string const & line, int lineCounter)
{
	int		year, month, day;
	float	amount;

	// Validate and parse the line
	if (!parseLine(line, year, month, day, amount, lineCounter))
		return;

	if (!validateParsedData(year, month, day, amount, line, lineCounter))
		return;
}

bool	BitcoinExchange::parseLine(std::string const & line, int &year, int &month, int &day, float &amount, int lineCounter)
{
	int	n = sscanf(line.c_str(), "%d-%d-%d | %f", &year, &month, &day, &amount);
	if (n != 4)
	{
		logFormatError(n, line, lineCounter);
		return false;
	}
	return true;
}

bool	BitcoinExchange::validateParsedData(int year, int month, int day, float amount, std::string const & line, int lineCounter)
{
	if (amount < 0 || amount > 1000)
	{
		logAmountError(line, lineCounter);
		return false;
	}

	(void)year;
	(void)month;
	(void)day;

	return true;
}

int	BitcoinExchange::isValidDate(std::tm timeInfo, int year, int month, int day)
{
	if (
			timeInfo.tm_year + 1900 != year ||
			timeInfo.tm_mon + 1 != month ||
			timeInfo.tm_mday != day
		)
		return (0);
	return (1);
}

void	BitcoinExchange::logFormatError(int n, std::string const & line, int lineCounter)
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << " Wrong format!" << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|" << BLACK << " expect 4 values (year-month-day | amount), but got only "
		<< n << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}

void	BitcoinExchange::logAmountError(std::string const & line, int lineCounter)
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << "Amount couldn't be negative or exceed 1000!" << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}

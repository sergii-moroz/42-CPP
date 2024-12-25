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
	int				lineCounter = 0;

	infile.open(BTC_DB, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenFileException();

	// int		year, month, day;
	// float	price;
	while (std::getline(infile, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		processDBLine(line, lineCounter);
		// int	n = sscanf(line.c_str(), "%d-%d-%d,%f", &year, &month, &day, &price);
		// if (n != 4)
		// {
		// 	std::cerr << std::endl;
		// 	std::cerr << RED << "ERROR |" << WHITE << " Wrong format!" << RESET << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " expect 4 values (year-month-day,price), but got only "
		// 		<< n << RESET << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
		// 	lineCounter++;
		// 	continue;
		// }
		// if (price < 0)
		// {
		// 	std::cerr << std::endl;
		// 	std::cerr << RED << "ERROR |" << WHITE << " Price couldn't be negative!" << RESET << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
		// 	lineCounter++;
		// 	continue;
		// }
		// if (year < 0 || month < 0 || day < 0)
		// {
		// 	std::cerr << std::endl;
		// 	std::cerr << "ERROR |" << WHITE << " Year||month||day couldn't be negative!" << RESET << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
		// 	lineCounter++;
		// 	continue;
		// }

		// std::tm	timeInfo = {};
		// timeInfo.tm_year = year - 1900;
		// timeInfo.tm_mon = month - 1;
		// timeInfo.tm_mday = day;
		// std::time_t	timestamp = std::mktime(&timeInfo);
		// if (timestamp == -1)
		// {
		// 	std::cerr << std::endl;
		// 	std::cerr << RED << "ERROR |" << WHITE << " time processing!" << RESET << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
		// 	lineCounter++;
		// 	continue;
		// }
		// if (!isValidDate(timeInfo, year, month, day))
		// {
		// 	std::cerr << std::endl;
		// 	std::cerr << RED << "ERROR |" << WHITE << " Wrong date value!" << RESET << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " date: " << CYAN << year << "-" << month << "-" << day
		// 		<< BLACK << " was converted to -> " << YELLOW << timeInfo.tm_year + 1900 << "-" << timeInfo.tm_mon + 1 << "-"
		// 		<< timeInfo.tm_mday << std::endl;
		// 	std::cerr << RED << std::setw(7) << "|"
		// 		<< BLACK << " [" << lineCounter << "] : \"" << CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
		// 	lineCounter++;
		// 	continue;
		// }

		// std::cout << line << std::endl;
		// std::cout << "timestamp: " << timestamp << std::endl;
		// db[timestamp] = price;
		lineCounter++;
	}
	infile.close();
	std::cout << "db size: " << db.size() << std::endl;
}

void	BitcoinExchange::evaluate(char *fileName) const
{
	std::cout << BLACK << "BitcoinExchange: evaluate function called" << RESET << std::endl;

	std::fstream	infile;
	std::string		line;
	int				lineCounter = 0;

	infile.open(fileName, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenFileException();

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

void	BitcoinExchange::processLine(std::string const & line, int lineCounter) const
{
	float	amount;
	std::tm	timeInfo = {};

	if (!parseLine(line, "%d-%d-%d | %f", timeInfo, amount, lineCounter))
		return;

	if (!validateParsedData(timeInfo, amount, line, lineCounter))
		return;

	if (!validateTimeInfo(timeInfo, line, lineCounter))
		return;

	processValidData(timeInfo, amount);
}

void	BitcoinExchange::processDBLine(std::string const & line, int lineCounter)
{
	float	price;
	std::tm	timeInfo = {};

	if (!parseLine(line, "%d-%d-%d,%f", timeInfo, price, lineCounter))
		return; //throw Exception

	if (!validatePrice(price, line, lineCounter))
		return; //throw Exception

	if (!validateTimeInfo(timeInfo, line, lineCounter))
		return;
}

bool	BitcoinExchange::parseLine(std::string const & line, std::string const & format, std::tm & timeInfo, float & amount, int lineCounter) const
{
	int	n = sscanf(line.c_str(), format.c_str(), &timeInfo.tm_year, &timeInfo.tm_mon, &timeInfo.tm_mday, &amount);
	if (n != 4)
	{
		logFormatError(n, line, lineCounter);
		return false;
	}
	return true;
}



void	BitcoinExchange::processValidData(std::tm & timeInfo, float amount) const
{
	char			buffer[80];
	std::time_t		timestamp = std::mktime(&timeInfo);
	float			price = getPrice(timestamp);

	if (price < 0)
	{
		std::cerr << "No data" << std::endl;
		return;
	}

	strftime(buffer, sizeof(buffer),"%Y-%m-%d", &timeInfo);

	std::cout << buffer << " => " << amount << " = "
		<< std::fixed << std::setprecision(1) << price * amount << std::endl;
}


bool	BitcoinExchange::validateTimeInfo(std::tm & timeInfo, std::string const & line, int lineCounter) const
{
	if (timeInfo.tm_year < 0 || timeInfo.tm_mon < 0 || timeInfo.tm_mday < 0)
	{
		logDateError(line, lineCounter);
		return false;
	}

	int	year, month, day;
	year = timeInfo.tm_year;
	month = timeInfo.tm_mon;
	day = timeInfo.tm_mday;

	timeInfo.tm_year = year - 1900;
	timeInfo.tm_mon = month - 1;
	timeInfo.tm_mday = day;

	std::time_t	timestamp = std::mktime(&timeInfo);
	if (timestamp == -1 || !isValidDate(timeInfo, year, month, day))
	{
		logInvalidDateError(timeInfo, year, month, day, line, lineCounter);
		return false;
	}

	return true;
}



bool	BitcoinExchange::validatePrice(float price, std::string const & line, int lineCounter) const
{
	if (price < 0)
	{
		logValueError(" Price couldn't be negative!", line, lineCounter);
		return false;
	}
	return true;
}



bool	BitcoinExchange::validateParsedData(std::tm & timeInfo, float amount, std::string const & line, int lineCounter) const
{
	if (amount < 0 || amount > 1000)
	{
		logValueError(" Amount couldn't be negative or exceed 1000!", line, lineCounter);
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidDate(std::tm timeInfo, int year, int month, int day) const
{
	if (
			timeInfo.tm_year + 1900 != year ||
			timeInfo.tm_mon + 1 != month ||
			timeInfo.tm_mday != day
		)
		return false;
	return true;
}



float	BitcoinExchange::getPrice(std::time_t timestamp) const
{
	std::map<std::time_t, double>::const_iterator	it = db.lower_bound(timestamp);
	if (it == db.end())
		it--;
		// return -1;
	return it->second;
}



// ==========================================
// Logs functions
// ==========================================

void	BitcoinExchange::logFormatError(int n, std::string const & line, int lineCounter) const
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << " Wrong format!" << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|" << BLACK << " expect 4 values (year-month-day, separator [\"|\" or \",\"], value), but got only "
		<< n << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}

void	BitcoinExchange::logValueError(std::string const & msg, std::string const & line, int lineCounter) const
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << msg << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}

void	BitcoinExchange::logDateError(std::string const & line, int lineCounter) const
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << " Year, month, or day couldn't be negative!" << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}

void	BitcoinExchange::logInvalidDateError(std::tm const & timeInfo, int year, int month, int day, std::string const & line, int lineCounter) const
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << " Wrong date value!" << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " date: " << CYAN << year << "-" << month << "-" << day
		<< BLACK << " was converted to -> "
		<< YELLOW << timeInfo.tm_year + 1900 << "-" << timeInfo.tm_mon + 1 << "-" << timeInfo.tm_mday << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}

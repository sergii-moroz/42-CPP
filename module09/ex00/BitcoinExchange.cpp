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
	// std::cout << BLACK << "BitcoinExchange: Default constructor called" << RESET << std::endl;
}



BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	// std::cout << BLACK << "BitcoinExchange: Copy constructor called" << RESET << std::endl;
	*this = copy;
}



// ==========================================
// Destructor
// ==========================================



BitcoinExchange::~BitcoinExchange()
{
	// std::cout << BLACK << "BitcoinExchange: Destructor called" << RESET << std::endl;
}



// ==========================================
// Assignment operator(=)
// ==========================================



BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{
		db = rhs.db;
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
	// std::cout << BLACK << "BitcoinExchange: loadDB function called" << RESET << std::endl;

	std::fstream	infile;
	std::string		line;
	int				lineCounter = 0;

	infile.open(BTC_DB, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenFileException();

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		processDBLine(line, lineCounter);
		lineCounter++;
	}
	infile.close();
	if (db.size() == 0)
		throw TooLowRecords();
}



void	BitcoinExchange::evaluate(char *fileName) const
{
	// std::cout << BLACK << "BitcoinExchange: evaluate function called" << RESET << std::endl;

	std::fstream	infile;
	std::string		line;
	int				lineCounter = 0;

	infile.open(fileName, std::ios::in);
	if (!infile.is_open())
		throw CouldNotOpenFileException();

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		processLine(line, lineCounter);
		lineCounter++;
	}
	infile.close();
}



// ==========================================
// Processing functions
// ==========================================



void	BitcoinExchange::processLine(std::string const & line, int lineCounter) const
{
	float	amount;
	std::tm	timeInfo = {};

	if (!parseLine(line, "%d-%d-%d | %f", timeInfo, amount, lineCounter))
		return;

	if (!validateAmount(amount, line, lineCounter))
		return;

	if (!validateTimeInfo(timeInfo, line, lineCounter))
		return;

	processValidData(timeInfo, amount, line, lineCounter);
}



void	BitcoinExchange::processDBLine(std::string const & line, int lineCounter)
{
	float	price;
	std::tm	timeInfo = {};

	if (!parseLine(line, "%d-%d-%d,%f", timeInfo, price, lineCounter))
		return;

	if (!validatePrice(price, line, lineCounter))
		return;

	if (!validateTimeInfo(timeInfo, line, lineCounter))
		return;

	addRecordToDB(timeInfo, price);
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



void	BitcoinExchange::processValidData(std::tm & timeInfo, float amount, std::string const & line, int lineCounter) const
{
	char			buffer[80];
	std::time_t		timestamp = std::mktime(&timeInfo);
	float			price = getPrice(timestamp);

	if (price < 0)
	{
		logNoDataError(line, lineCounter);
		return;
	}

	strftime(buffer, sizeof(buffer),"%Y-%m-%d", &timeInfo);

	std::cout << buffer << " => " << amount << " = "
		<< std::fixed << std::setprecision(2) << price * amount << std::endl;
}



// ==========================================
// Validation functions
// ==========================================



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



bool	BitcoinExchange::validateAmount(float amount, std::string const & line, int lineCounter) const
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



// ==========================================
// Getter / Setter
// ==========================================



float	BitcoinExchange::getPrice(std::time_t timestamp) const
{
	std::map<std::time_t, double>::const_iterator	it = db.lower_bound(timestamp);
	if (it == db.begin())
	{
		if (it->first > timestamp)
			return -1;
		else
			return it->second;
	}
	else if (it == db.end())
	{
		it--;
		return it->second;
	}
	else if (it->first > timestamp)
	{
		it--;
		return it->second;
	}
	return it->second;
}



void	BitcoinExchange::addRecordToDB(std::tm & timeInfo, float price)
{
	std::time_t	timestamp = std::mktime(&timeInfo);
	db[timestamp] = price;
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

void	BitcoinExchange::logNoDataError(std::string const & line, int lineCounter) const
{
	std::cerr << std::endl;
	std::cerr << RED << "ERROR |" << WHITE << " No record in DB that less then specified date!" << RESET << std::endl;
	std::cerr << RED << std::setw(7) << "|"
		<< BLACK << " [" << lineCounter << "] : \""
		<< CYAN << line << BLACK << "\" - line would be ignored" << RESET << std::endl;
}


// ==========================================
// Exceptions
// ==========================================



const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ( RED "ERROR: " RESET "Couldn't open file!");
}

const char *BitcoinExchange::TooLowRecords::what() const throw()
{
	return ( RED "\nERROR |" RESET " Too low records in DB!\n" RED "      |" RESET " => exit!");
}

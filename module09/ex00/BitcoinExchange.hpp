/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:13:24 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/19 16:07:04 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m"

# define BTC_DB		"data.csv"

# include <algorithm>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <ctime>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &);
		BitcoinExchange &	operator=(BitcoinExchange const &);

		static void	usage(void);
		void		loadDB(void);
		void		evaluate(char *fileName) const;

		class CouldNotOpenFileException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class TooLowRecords: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::map<std::time_t, double>	db;

		// processing functions
		void	processDBLine(std::string const & line, int lineCounter);
		void	processValidData(std::tm & timeInfo, float amount, std::string const & line, int lineCounter) const;
		void	processLine(std::string const & line, int lineCounter) const;
		bool	parseLine(std::string const & line, std::string const & format, std::tm & timeInfo, float & amount, int lineCounter) const;

		// validation functions
		bool	isValidDate(std::tm timeInfo, int year, int month, int day) const;
		bool	validatePrice(float price, std::string const & line, int lineCounter) const;
		bool	validateAmount(float amount, std::string const & line, int lineCounter) const;
		bool	validateTimeInfo(std::tm & timeInfo, std::string const & line, int lineCounter) const;

		// getter / setter
		float	getPrice(std::time_t timestamp) const;
		void	addRecordToDB(std::tm & timeInfo, float price);

		// logs
		void	logDateError(std::string const & line, int lineCounter) const;
		void	logNoDataError(std::string const & line, int lineCounter) const;
		void	logFormatError(int n, std::string const & line, int lineCounter) const;
		void	logValueError(std::string const & msg, std::string const & line, int lineCounter) const;
		void	logInvalidDateError(std::tm const & timeInfo, int year, int month, int day, std::string const & line, int lineCounter) const;
};

#endif

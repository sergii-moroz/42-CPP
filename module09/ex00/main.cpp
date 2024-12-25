/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:56 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/19 15:47:36 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		BitcoinExchange::usage();
		return (1);
	}

	BitcoinExchange	btc;
	try
	{
		btc.loadDB();
		btc.evaluate(argv[1]);
	}
	catch(std::exception const & e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}

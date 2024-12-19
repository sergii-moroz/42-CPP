/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:14:56 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/19 15:31:21 by smoroz           ###   ########.fr       */
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
	btc.loadDB();

	std::cout << argv[0] << std::endl;
	return (0);
}

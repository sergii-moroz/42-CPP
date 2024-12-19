/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:36:16 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/19 15:38:08 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ==========================================
// Exceptions
// ==========================================

const char *BitcoinExchange::CouldNotOpenDBFileException::what() const throw()
{
	return ( RED "ERROR: " RESET "Couldn't open the Bitcoin DB file!");
}

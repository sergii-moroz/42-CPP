/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:59:03 by smoroz            #+#    #+#             */
/*   Updated: 2024/12/26 13:59:03 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0]
			<< " <space separated list of positive integers>" << std::endl;
		std::cerr << std::setw(16) << argv[0]
			<< " 25 1 48 24 75 13 8" << std::endl;
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:46:47 by smoroz            #+#    #+#             */
/*   Updated: 2024/11/07 14:46:47 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout
			<< "ERROR: Invalid input" << std::endl
			<< "   Only one argument is expected. Got (" << argc - 1 << ")" << std::endl
			<< "   Example: ./RPN \"3 4 + 5 *\"" << std::endl;
		return (1);
	}

	try
	{
		std::cout << RPN::calc(argv[1]) << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}

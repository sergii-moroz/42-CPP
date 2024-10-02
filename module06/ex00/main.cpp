/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:56:33 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/02 16:02:14 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	usage(void)
{
	std::cout << "Usage: ./convert ONE_PARAMETER" << std::endl
		<< "Example: ./convert -42.0f" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		usage();
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

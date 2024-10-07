/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:02:48 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 18:13:48 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	*p;
	Data	*m;

	p = new Data(1, 3.14, "Apple");
	std::cout << MAGENTA << "Before serialize" << RESET << std::endl;
	std::cout << BLACK << "address: " << CYAN << p
		<< BLACK << "Data: " << CYAN << *p << RESET << std::endl;

	m = Serializer::deserialize(Serializer::serialize(p));
	std::cout << MAGENTA << "After serialize" << RESET << std::endl;
	std::cout << BLACK << "address: " << CYAN << p
		<< BLACK << "Data: " << CYAN << *p << RESET << std::endl;
	delete p;
	return (0);
}

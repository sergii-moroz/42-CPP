/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:39:55 by smoroz            #+#    #+#             */
/*   Updated: 2024/08/28 20:32:50 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	noname;
	ScavTrap	bob("bob");
	ScavTrap	bob2 = bob;

	std::cout << noname << std::endl;
	std::cout << bob << std::endl;
	std::cout << bob2 << std::endl;

	bob.attack(noname.getName());
	bob.guardGate();
	std::cout << bob << std::endl;
	noname = bob;
	std::cout << noname << std::endl;


	return (0);
}

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

#include "DiamondTrap.hpp"

int	main(void)
{
	// Constructors
	DiamondTrap	b;
	// DiamondTrap	b("bob");
	// DiamondTrap	c(b);
	std::cout << b << std::endl;

	// Attack
	b.attack("robot 1");
	std::cout << b << std::endl;

	// Take Damage
	b.takeDamage(15);
	std::cout << b << std::endl;

	// Repair
	b.beRepaired(28);
	std::cout << b << std::endl;

	// Custom functions
	b.whoAmI();
	b.highFivesGuys();
	b.guardGate();

	// Die
	// Do something after death

	return (0);
}

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

#include "ClapTrap.hpp"

int	main(void)
{
	// Constructors
	ClapTrap	b;
	// ClapTrap	b("bob");
	// ClapTrap	c(b);
	std::cout << b << std::endl;

	// Attack
	std::cout << std::endl << "=== Test 1 ===" << std::endl;
	b.attack("robot 1");
	std::cout << b << std::endl;

	// Attack
	b.setAttackDamage(1);
	std::cout << std::endl << "=== Test 2 ===" << std::endl;
	b.attack("robot 1");
	std::cout << b << std::endl;

	// Take Damage
	std::cout << std::endl << "=== Test 3 ===" << std::endl;
	b.takeDamage(5);
	std::cout << b << std::endl;

	// Repair
	std::cout << std::endl << "=== Test 4 ===" << std::endl;
	b.beRepaired(1);
	std::cout << b << std::endl;

	// loose all energy
	std::cout << std::endl << "=== Test 5 ===" << std::endl;
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	b.attack("someone");
	std::cout << b << std::endl;

	// Die
	std::cout << std::endl << "=== Test 6 ===" << std::endl;
	b.takeDamage(1000);
	std::cout << b << std::endl;

	// Do something after death
	std::cout << std::endl << "=== Test 7 ===" << std::endl;
	b.beRepaired(5);
	b.attack("Robot");

	return (0);
}

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
	ClapTrap	bob("Bob");
	ClapTrap	sven("Sven");

	std::cout << bob << std::endl;
	std::cout << sven << std::endl;
	bob.setAttackDamage(2);
	bob.attack(sven.getName());
	sven.takeDamage(bob.getAttackDamage());
	sven.beRepaired(1);
	sven.beRepaired(1);
	sven.beRepaired(1);
	std::cout << bob << std::endl;
	std::cout << sven << std::endl;
	//ct1 = ct2;
	//std::cout << ct1 << std::endl;
	return (0);
}

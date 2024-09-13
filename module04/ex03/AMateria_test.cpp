/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:07:30 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/12 20:30:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Test.hpp"

int	main(void)
{
	AMateria	*materias[4];

	Test::caption("Create two ice materia & two cure materia");
	materias[0] = new Ice();
	materias[1] = new Cure();
	materias[2] = new Ice();
	materias[3] = new Cure();
	for (int i = 0; i < 4; i++)
	{
		std::cout << "[ "<< i << " ] address: " << materias[i]
			<< ", type: " << materias[i]->getType() << std::endl;
	}

	Test::caption("Assignment: x = x");
	*materias[0] = *materias[0];
	*materias[3] = *materias[2];
	for (int i = 0; i < 4; i++)
	{
		std::cout << "[ "<< i << " ] address: " << materias[i]
			<< ", type: " << materias[i]->getType() << std::endl;
	}

	{
		Test::caption("Copy constructor");
		Ice tmp0 = Ice();
		Ice tmp1 = Ice(tmp0);
	}

	Test::caption("Destructor");
	for (int i = 0; i < 4; i++)
		delete materias[i];

	return (0);
}

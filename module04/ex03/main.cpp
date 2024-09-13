/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:19:01 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/10 09:40:13 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main(void)
{
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		ICharacter	*me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter	*bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
		std::cout << std::endl;
	}//*/

	{
		std::cout << "TEST : Character's Copy constructor && deep copy" << std::endl;
		Character *ch1 = new Character("bob");
		ICharacter *ch2 = new Character(*ch1);
		delete ch1;
		delete ch2;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST : Check Character max slots" << std::endl;
		AMateria	*tmp;
		ICharacter	*bob = new Character("bob");
		tmp = new Ice();
		bob->equip(tmp);

		tmp = new Cure();
		bob->equip(tmp);

		tmp = new Ice();
		bob->equip(tmp);

		tmp = new Cure();
		bob->equip(tmp);

		tmp = new Cure();
		bob->equip(tmp);

		delete bob;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST : Check Character equip/unequip" << std::endl;
		AMateria	*tmp;
		ICharacter	*bob = new Character("bob");
		tmp = new Ice();
		bob->equip(tmp);
		bob->equip(new Cure());

		bob->unequip(-1);
		bob->unequip(4);
		bob->unequip(0);

		delete bob;
		delete tmp;
		std::cout << std::endl;
	}

	{
		std::cout << "TEST : Use materias on character" << std::endl;
		ICharacter	*bob = new Character("bob");
		ICharacter	*zombie = new Character("zombie");

		bob->equip(new Ice());
		bob->equip(new Cure());

		bob->use(0, *zombie);
		bob->use(1, *zombie);
		bob->use(2, *zombie);
		bob->use(3, *zombie);
		bob->use(-5, *zombie);
		bob->use(10, *zombie);

		delete bob;
		delete zombie;
		std::cout << std::endl;
	}

	return (0);
}

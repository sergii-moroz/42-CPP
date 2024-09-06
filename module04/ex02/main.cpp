/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:08:57 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/06 20:09:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void	ft_leaks(void)
{
	system("leaks brain");
}

int	main( void )
{
	Cat	cbasic;
	Dog	dbasic;
	{
		Cat	ctmp = cbasic;
		Dog	dtmp = dbasic;
	}
	// atexit(ft_leaks);
	const int	i_max = 2;

	AAnimal	*animal[i_max];
	for (int i = 0; i < i_max; i++)
	{
		std::cout << std::endl << "i: " << i << " - Creating ... " << std::endl;
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
		std::cout << "... " << animal[i]->getType() << " was created" << std::endl;
	}

	for (int i = 0; i < i_max; i++)
	{
		std::cout << std::endl << "i: " << i << " - Deleting ... " << animal[i]->getType() << std::endl;
		delete animal[i];
	}
	return (0);
}

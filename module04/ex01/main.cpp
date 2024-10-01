/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:08:57 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/01 11:12:25 by smoroz           ###   ########.fr       */
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
	std::cout << "=== Test 0: Create Cat, Dog ===" << std::endl;
	Cat	cbasic;
	Dog	dbasic;
	std::cout << "=== END: Test 0 ===" << std::endl << std::endl;

	std::cout << "=== Test 1: Assign ===" << std::endl;
	{
		Cat	ctmp = cbasic;
		Dog	dtmp = dbasic;
	}
	std::cout << "=== END: Test 1 ===" << std::endl << std::endl;
	// atexit(ft_leaks);

	std::cout << "=== Test 2: Fill array of Animals with Cat, Dog [50%, 50%] ===" << std::endl;
	const int	i_max = 2;
	Animal		*animal[i_max];
	for (int i = 0; i < i_max; i++)
	{
		std::cout << std::endl << "i: " << i << " - Creating ... " << std::endl;
		if (i % 2 == 0)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
		std::cout << "... " << animal[i]->getType() << " was created" << std::endl;
	}
	std::cout << "=== END: Test 2 ===" << std::endl << std::endl;

	std::cout << "=== Test 3: Looo over the array and delete every Animal ===" << std::endl;
	for (int i = 0; i < i_max; i++)
	{
		std::cout << std::endl << "i: " << i << " - Deleting ... " << animal[i]->getType() << std::endl;
		delete animal[i];
	}
	std::cout << "=== END: Test 3 ===" << std::endl << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/04 09:28:21 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	std::cout << "=== Test 1 === start" << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*meta_copy = new Animal(*meta);
	std::cout << "Type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;
	delete meta_copy;
	std::cout << "=== Test 1 === end" << std::endl << std::endl;

	std::cout << "=== Test 2 === start" << std::endl;
	const Cat	*cat = new Cat();
	const Cat	*cat_copy = new Cat(*cat);
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;
	delete cat_copy;
	std::cout << "=== Test 2 === end" << std::endl << std::endl;

	std::cout << "=== Test 3 === start" << std::endl;
	const Dog	*dog = new Dog();
	const Dog	*dog_copy = new Dog(*dog);
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;
	delete dog_copy;
	std::cout << "=== Test 3 === end" << std::endl << std::endl;

	std::cout << "=== Test 4 === start" << std::endl;
	const WrongAnimal	*wmeta = new WrongAnimal();
	const WrongAnimal	*wmeta_copy = new WrongAnimal(*wmeta);
	std::cout << "Type: " << wmeta->getType() << std::endl;
	wmeta->makeSound();
	delete wmeta;
	delete wmeta_copy;
	std::cout << "=== Test 4 === end" << std::endl << std::endl;

	std::cout << "=== Test 5 === start" << std::endl;
	const WrongCat	*wcat = new WrongCat();
	const WrongCat	*wcat_copy = new WrongCat(*wcat);
	std::cout << "Type: " << wcat->getType() << std::endl;
	wcat->makeSound();
	delete wcat;
	delete wcat_copy;
	std::cout << "=== Test 5 === end" << std::endl << std::endl;

	return (0);
}

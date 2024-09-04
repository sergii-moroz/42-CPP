/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:10 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/04 08:37:50 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

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

	return (0);
}

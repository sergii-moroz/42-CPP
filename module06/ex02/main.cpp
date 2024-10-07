/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:19:36 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/07 20:37:14 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << CYAN << "class \"A\" is identified" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << YELLOW << "class \"B\" is identified" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << GREEN << "class \"C\" is identified" << RESET << std::endl;
	else
		std::cout << RED << "ERROR: " << RESET << "couldn't identify class" << std::endl;
}

void	identify(Base & ref)
{
	try
	{
		std::cout << BLACK << "Trying identify class \"A\"... " << RESET << std::endl;
		Base &b = dynamic_cast<A &>(ref);
		std::cout << CYAN << "class \"A\" is identified successfully" << RESET << std::endl;
		(void)b;
		return ;
	}
	catch(std::exception const & e)
	{
		std::cout << BLACK << "Attempt to identify class \"A\" is failed" << RESET << std::endl;
	}

	try
	{
		std::cout << BLACK << "Trying identify class \"B\"... " << RESET << std::endl;
		Base &b = dynamic_cast<B &>(ref);
		std::cout << YELLOW << "class B is identified successfully" << RESET << std::endl;
		(void)b;
		return ;
	}
	catch(std::exception const & e)
	{
		std::cout << BLACK << "Attempt to identify class \"B\" is failed" << RESET << std::endl;
	}

	try
	{
		std::cout << BLACK << "Trying identify class \"C\"... " << RESET << std::endl;
		Base &b = dynamic_cast<C &>(ref);
		std::cout << GREEN << "class C is identified successfully" << RESET << std::endl;
		(void)b;
		return ;
	}
	catch(std::exception const & e)
	{
		std::cout << BLACK << "Attempt to identify class \"B\" is failed" << RESET << std::endl;
	}

}

int	main(void)
{

	std::srand(std::clock());
	Base	*p = generate();

	std::cout << MAGENTA << "=== Test 1: void identify(Base *p) ===" << RESET << std::endl;
	identify(p);

	std::cout << MAGENTA << "=== Test 2: void identify(Base & ref) ===" << RESET << std::endl;
	identify(*p);

	delete p;
	return (0);
}

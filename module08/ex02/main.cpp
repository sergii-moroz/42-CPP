/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:44:39 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/16 09:44:39 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
// #include <stack>
// #include <iostream>

int	main(void)
{
	// std::stack<int> stack;
	MutantStack<int>	stack;
	stack.push(99);
	stack.push(12);
	std::cout << stack.top() << std::endl;
	std::cout << *(&(stack.top()) - 1) << std::endl;

	// end() = &(stack.top()) + 1
	// begin() = &(stack.top()) - size()

	return (0);
}

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
#include <string>

int	main(void)
{
	{
		std::cout << MAGENTA << "==========================================" << std::endl;
		std::cout << "MutantStack<" << CYAN << "int" << MAGENTA << ">" << std::endl;
		std::cout << "==========================================" << RESET << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "push 5 17: top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "pop(), size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "push 3 5 737 0: top: " << mstack.top() << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "mstack { ";
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "}" << std::endl;

		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl;
		std::cout << MAGENTA << "==========================================" << std::endl;
		std::cout << "MutantStack<" << CYAN << "std::string" << MAGENTA << ">" << std::endl;
		std::cout << "==========================================" << RESET << std::endl;

		MutantStack<std::string> mstack;
		mstack.push("five");
		mstack.push("seventeen");
		std::cout << "push 5 17: top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "pop(), size: " << mstack.size() << std::endl;
		mstack.push("three");
		mstack.push("one");
		mstack.push("forty two");
		std::cout << "push() 3 1 42: top: " << mstack.top() << std::endl;
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "mstack { ";
		while (it != ite)
		{
			std::cout << "\"" << *it << "\" ";
			++it;
		}
		std::cout << "}" << std::endl;

		std::cout << BLACK << "reverse" << RESET << std::endl;
		MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
		MutantStack<std::string>::reverse_iterator rite = mstack.rend();
		std::cout << "mstack { ";
		while (rit != rite)
		{
			std::cout << "\"" << *rit << "\" ";
			++rit;
		}
		std::cout << "}" << std::endl;

		std::stack<std::string> s(mstack);
	}

	return (0);
}

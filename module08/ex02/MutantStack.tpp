/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:57:28 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/16 17:57:28 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// ==========================================
// Constructors
// ==========================================

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << BLACK << "MutantStack: Default constructor called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & copy) : std::stack<T>(copy)
{
	std::cout << BLACK << "MutantStack: Copy constructor called" << RESET << std::endl;
}

// ==========================================
// Destructor
// ==========================================

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << BLACK << "MutantStack: Destructor called" << RESET << std::endl;
}

// ==========================================
// Assignment operator(=)
// ==========================================

template <typename T>
MutantStack<T> &	MutantStack<T>::operator=(MutantStack const & rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return (*this);
}

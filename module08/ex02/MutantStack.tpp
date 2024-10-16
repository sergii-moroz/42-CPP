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
MutantStack<T>::MutantStack()
{
	std::cout << BLACK << "MutantStack: Default constructor called" << RESET << std::endl;
}

// ==========================================
// Destructor
// ==========================================

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << BLACK << "MutantStack: Destructor called" << RESET << std::endl;
}

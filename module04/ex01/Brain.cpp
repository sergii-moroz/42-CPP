/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:36:13 by smoroz            #+#    #+#             */
/*   Updated: 2024/10/01 10:31:37 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain( Brain const & copy )
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = copy;
}

Brain &	Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain: Assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i].assign(rhs._ideas[i]);
	return (*this);
}

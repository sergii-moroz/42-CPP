/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoroz <smoroz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:58:38 by smoroz            #+#    #+#             */
/*   Updated: 2024/09/11 21:48:09 by smoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{
	std::cout << "MateriaSource: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_materials[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
	{
		std::cout << "MateriaSource: There is no need to use assignment operator [lhs==rhs]" << std::endl;
		return (*this);
	}
	std::cout << "MateriaSource: Assignment operator called" << std::endl;
	_idx = rhs._idx;
	for (int i = 0; i < 4; i++)
		_materials[i] = rhs._materials[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_idx < 4)
	{
		_materials[_idx] = m;
		_idx++;
		std::cout << "MateriaSource: New materia of type "
			<< m->getType() << " was learnd" << std::endl;
	}
	else
		std::cout << "MateriaSource: Couldn't learn new materia. All slots are occupied" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i]->getType() == type )
			return (_materials[i]->clone());
	}
	return (NULL);
}

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

// =========================================================
// constructors
// =========================================================

MateriaSource::MateriaSource()
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

// =========================================================
// destructor
// =========================================================

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_materials[i])
			delete _materials[i];
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		std::cout << "MateriaSource: There is no need to use assignment operator [lhs==rhs]" << std::endl;
	else
	{
		std::cout << "MateriaSource: Assignment operator called" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			if (_materials[i])
				delete _materials[i];
			if (rhs._materials[i] != NULL)
				_materials[i] = rhs._materials[i]->clone();
			else
				_materials[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i] == NULL)
		{
			_materials[_idx] = m;
			std::cout << "MateriaSource: New materia of type "
				<< m->getType() << " was learned" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource: Couldn't learn new materia. All slots are occupied" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i] !=NULL && _materials[i]->getType() == type )
			return (_materials[i]->clone());
	}
	std::cout << "MateriaSource: Materia \"" << type << "\" should be learned first" << std::endl;
	return (NULL);
}

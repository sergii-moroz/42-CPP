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
	std::cout << "MateriaSource: " << BLACK
		<< "Default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_materials[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy) : IMateriaSource()
{
	std::cout << "MateriaSource: " << BLACK
		<< "Copy constructor called" << RESET << std::endl;
	*this = copy;
}

// =========================================================
// destructor
// =========================================================

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: " << BLACK
		<< "Destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		if (_materials[i])
			delete _materials[i];
}

// =========================================================
// Assignment = operator's overloading
// =========================================================

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		std::cout << "MateriaSource: " << RED
			<< "There is no need to use assignment operator [lhs==rhs]" << std::endl;
	else
	{
		std::cout << "MateriaSource: " << BLACK
			<< "Assignment operator called" << RESET << std::endl;
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

// =========================================================
// member function
// =========================================================

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i] == NULL)
		{
			_materials[i] = m;
			std::cout << "MateriaSource: " << GREEN << "New materia of type "
				<< m->getType() << " was learned" << RESET << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource: " << RED
		<< "Couldn't learn new materia. All slots are occupied" << RESET << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materials[i] !=NULL && _materials[i]->getType() == type )
			return (_materials[i]->clone());
	}
	std::cout << "MateriaSource: " << RED << "Materia \""
		<< type << "\" should be learned first" << RESET << std::endl;
	return (NULL);
}

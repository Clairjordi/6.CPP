/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:18:36 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 20:05:28 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* Constructor and Destructor */
MateriaSource::MateriaSource(void)
{
}

MateriaSource::MateriaSource(const MateriaSource& toCopy)
{
	*this = toCopy;
}

MateriaSource::~MateriaSource(void)
{
}

/* Member Function */
void MateriaSource::learnMateria(AMateria* m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_arrayMateria[i] == NULL)
			break ;
	}
	if (i < 4)
		_arrayMateria[i] = m;

}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_arrayMateria[i] && _arrayMateria[i]->getType() == type)
			break ;
	}
	if (i > 3)
		return 0;
	return _arrayMateria[i]->clone() ;
}

/* Operator */
MateriaSource& MateriaSource::operator=(const MateriaSource& toCopy)
{
	if (this != &toCopy)
	{
		// delete ?
		for (int i = 0; i < 4; i++)
			_arrayMateria[i] = toCopy._arrayMateria[i];
	}
	return *this;
}


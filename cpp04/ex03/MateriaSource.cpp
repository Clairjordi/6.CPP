/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:18:36 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 23:41:58 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* Constructor and Destructor */
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_arrayMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& toCopy)
{	
	for (int i = 0; i < 4; i++)
		_arrayMateria[i] = NULL;

	*this = toCopy;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete _arrayMateria[i];
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
	else 
		delete m;
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
		for (int i = 0; i < 4; i++)
			if (toCopy._arrayMateria[i])
				_arrayMateria[i] = toCopy._arrayMateria[i]->clone();
			else
				_arrayMateria[i] = NULL;
	}
	return *this;
}


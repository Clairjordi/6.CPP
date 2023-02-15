/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:10 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 23:32:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* Constructor and Destructor */
Character::Character(void)
{
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
	for (int i = 0; i < 42; i++)
		_trash[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{	
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
	for (int i = 0; i < 42; i++)
		_trash[i] = NULL;

}

Character::Character(const Character& toCopy)
{	
	for (int i = 0; i < 4; i++)
		_items[i] = NULL;
	for (int i = 0; i < 42; i++)
		_trash[i] = NULL;

	*this = toCopy;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete _items[i];
	for (int i = 0; i < 42; i++)
		delete _trash[i];
}

/* Member Function */
std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (m != NULL)
	{	
		int i;
		for (i = 0; i < 4; i++)
		{
			if (!_items[i])
				break ;
		}
		if (i > 3)
			return ;
		_items[i] = m;
	}
}

void Character::unequip(int idx)
{
	if ((idx < 0 || idx > 3) || _items[idx] == NULL) 
			return ;
	int i;
	for (i = 0; i < 42; i++)
	{
		if (!_trash[i])
			break ;
	}
	_trash[i] = _items[idx];
	_items[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx >= 0 && idx < 4) && _items[idx] != NULL)
	{
		_items[idx]->use(target);
	}
}

/* Operator */
Character& Character::operator=(const Character& toCopy)
{
	if (this != &toCopy)
	{
		_name = toCopy._name;
		for (int i = 0; i < 4; i++)
		{
			if (toCopy._items[i] != NULL)
				_items[i] = toCopy._items[i]->clone();
			else
				_items[i] = NULL;
		}
	}
	return *this;
}

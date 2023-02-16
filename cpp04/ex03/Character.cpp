/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:19:10 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/16 12:00:19 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* Constructor and Destructor */
Character::Character(void) : _name("anyone")
{
	for (int i = 0; i < 4; i++)
		_itemsInventory[i] = NULL;
	for (int i = 0; i < 42; i++)
		_trash[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{	
	for (int i = 0; i < 4; i++)
		_itemsInventory[i] = NULL;
	for (int i = 0; i < 42; i++)
		_trash[i] = NULL;

}

Character::Character(const Character& toCopy)
{	
	for (int i = 0; i < 4; i++)
		_itemsInventory[i] = NULL;
	for (int i = 0; i < 42; i++)
		_trash[i] = NULL;

	*this = toCopy;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete _itemsInventory[i];
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
			if (!_itemsInventory[i])
				break ;
		}
		if (i > 3)
			return ;
		_itemsInventory[i] = m;
	}
}

void Character::unequip(int idx)
{
	if ((idx < 0 || idx > 3) || _itemsInventory[idx] == NULL) 
			return ;
	int i;
	for (i = 0; i < 42; i++)
	{
		if (!_trash[i])
			break ;
	}
	_trash[i] = _itemsInventory[idx];
	_itemsInventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx >= 0 && idx < 4) && _itemsInventory[idx] != NULL)
	{
		_itemsInventory[idx]->use(target);
	}
}

/* Operator */
Character& Character::operator=(const Character& toCopy)
{
	if (this != &toCopy)
	{
		_name = toCopy._name;
		for (int i = 0; i < 4; i++)
			delete _itemsInventory[i];
		for (int i = 0; i < 4; i++)
		{
			if (toCopy._itemsInventory[i] != NULL)
				_itemsInventory[i] = toCopy._itemsInventory[i]->clone();
			else
				_itemsInventory[i] = NULL;
		}
	}
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:59:54 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/11 12:03:34 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructors & destructors
ClapTrap::ClapTrap(void) : _name("no name"), _hit(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name; 
		_hit = rhs._hit;
		_energy = rhs._energy;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// functions
std::string ClapTrap::getName() const
{
	return _name;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target) 
{
	if (_energy > 0 && _hit > 0)
	{
		std::cout << "~~" << _name << " attacks " << target;
		std::cout << ", causing " <<  _attackDamage << " damage points!" << std::endl;
		_energy -= 1;
		std::cout << _name << " has " << _energy << " energy points.~~" << std::endl; 
	}
	else
		std::cout << "Sorry " << _name << ", your energy or hit is empty, you can't attack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hit -= amount;
	std::cout << _name << " suffered " << amount << " damages !";
	if (_hit < 0)
	{
		_hit = 0;
		std::cout << " So " << _name;
		std::cout <<  ", who cannot have a negative life, has " << _hit << " life points." << std::endl;
	}
	else 
		std::cout << " So " << _name <<  ", has " << _hit << " life points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0)
	{
		std::cout << _name << " has no more life points, so it's too late to repair !" << std::endl;
		return ;
	}
	if (_energy > 0)
	{
		_hit += amount;
		std::cout << "~~" << _name << " has been repaired by " << amount << " points !";
		std::cout << " So " << _name <<  " has " << _hit << " life points." << std::endl;
		_energy -= 1;	
		std::cout << _name << " has " << _energy << " energy points.~~" << std::endl; 
	}
	else
		std::cout << "Sorry " << _name << ", your energy is empty, you can't fix yourself" << std::endl;
}

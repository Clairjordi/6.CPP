/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:59:54 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/10 18:59:35 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
	if (_energy > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " <<  _attackDamage << " points of damage!" << std::endl;
		_energy -= 1;
		std::cout << "ClapTrap " << _name << " has " << _energy << " energy's points" << std::endl;  
	}
	else
		std::cout << "Sorry, your energy is empty, you can't attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hit -= amount;
	std::cout << "ClapTrap " << _name << " suffered " << amount << " damages !";
	std::cout << " So " << _name <<  " has " << _hit << " points of life" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		_hit += amount;
		std::cout << "ClapTrap " << _name << " has been repaired by " << amount << " points !";
		std::cout << " So " << _name <<  " has " << _hit << " points of life" << std::endl;
		_energy -= 1;
		std::cout << "ClapTrap " << _name << " has " << _energy << " energy's points" << std::endl; 
	}
	else
		std::cout << "Sorry, your energy is empty, you can't fix yourself" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:13 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/11 12:01:51 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructors & destructors
ScavTrap::ScavTrap(void) : ClapTrap() 
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name; 
		_hit = rhs._hit;
		_energy = rhs._energy;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// functions
void ScavTrap::attack(const std::string& target) 
{
	if (_energy > 0 && _hit > 0)
	{
		std::cout << "~~" <<  _name << " attacks " << target;
		std::cout << ", the cunning one ! It causes " <<  _attackDamage << " damage points!" << std::endl;
		_energy -= 1;
		std::cout << _name << " has " << _energy << " energy points.~~" << std::endl; 
	}
	else
		std::cout << "Sorry " << _name << ", your energy or hit is empty, you can't attack !" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << _name << " went into gatekeeper mode." << std::endl;
}

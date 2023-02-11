/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:13 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/11 12:15:09 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// constructors & destructors
FragTrap::FragTrap(void) : ClapTrap() 
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name; 
		_hit = rhs._hit;
		_energy = rhs._energy;
		_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

// functions
void FragTrap::highFivesGuys(void)
{
	std::cout << _name << " has a resquest : please high fives !" << std::endl;
}

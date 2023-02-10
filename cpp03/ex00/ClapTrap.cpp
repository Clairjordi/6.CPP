/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:59:54 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/09 18:21:56 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructor and Destructor */

ClapTrap::ClapTrap(void) : _name("no name"), _hit(10), _energy(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
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
		_name = rhs._name; 
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

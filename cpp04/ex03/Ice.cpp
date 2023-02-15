/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:29 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 19:24:16 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* Constructor and Destructor */
Ice::Ice(void) : AMateria()
{
	_type = "ice";
}

Ice::Ice(const Ice& toCopy) : AMateria(toCopy)
{
	*this = toCopy;
}

Ice::~Ice(void)
{
}

/* Member Function */
Ice* Ice::clone() const
{
	Ice* cloneIce = new Ice();
	return cloneIce;
}

void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}

/* Operator */
Ice& Ice::operator=(const Ice& toCopy)
{
	if (this != &toCopy)
	{
		//inutile de copier le type ?
		_type = toCopy._type;
	}
	return *this;
}


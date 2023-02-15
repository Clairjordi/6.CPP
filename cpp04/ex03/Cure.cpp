/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:29 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 23:20:52 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* Constructor and Destructor */
Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure& toCopy) : AMateria(toCopy)
{
	*this = toCopy;
}

Cure::~Cure(void)
{
}

/* Member Function */
Cure* Cure::clone() const
{
	Cure* cloneCure = new Cure();
	return cloneCure;
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/* Operator */
Cure& Cure::operator=(const Cure& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return *this;
}


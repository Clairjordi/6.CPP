/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:37:59 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 19:24:43 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* Constructor and Destructor */
AMateria::AMateria(void)
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& toCopy)
{
	*this = toCopy;
}

AMateria::~AMateria(void)
{
}

/* Member Function */
std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter & target)
{
	std::cout << "Use " << _type << " at " << target.getName() << std::endl;
}

/* Operator */
AMateria& AMateria::operator=(const AMateria& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return *this;
}


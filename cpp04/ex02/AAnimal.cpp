/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:15 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 18:54:42 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* Constructor and Destructor */
AAnimal::AAnimal(void) : _type("Any animal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& toCopy)
{
	*this = toCopy;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

/* Member Function */
std::string AAnimal::getType() const
{
	return (_type);
}

/* Operator */
AAnimal& AAnimal::operator=(const AAnimal& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}


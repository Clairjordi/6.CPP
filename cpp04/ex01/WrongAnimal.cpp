/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:47:55 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 17:24:25 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* Constructor and Destructor */
WrongAnimal::WrongAnimal(void) : _type("wrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& toCopy)
{
	*this = toCopy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* Member Function */
void WrongAnimal::makeSound() const
{
	std::cout << "HelloKitty said : grey isn't my color !" << std::endl;
}

/* Operator */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}


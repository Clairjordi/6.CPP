/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:15 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 18:45:48 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* Constructor and Destructor */
Animal::Animal(void) : _type("Any animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& toCopy)
{
	*this = toCopy;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/* Member Function */
std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "It's an animal, as it's the one you want, make the sound you wish" << std::endl;	
}


/* Operator */
Animal& Animal::operator=(const Animal& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}


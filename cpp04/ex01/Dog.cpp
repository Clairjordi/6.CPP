/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:51:47 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 18:23:48 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* Constructor and Destructor */
Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy)
{
	*this = toCopy;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

/* Member Function */
void Dog::makeSound() const
{
	std::cout << "The dog goes woof" << std::endl;
}

/* Operator */
Dog& Dog::operator=(const Dog& toCopy)
{
	if (this != &toCopy)
	{
		_type = toCopy._type;
		*_brain = *toCopy._brain;
	}
	return (*this);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:19:15 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 18:28:02 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Constructor and Destructor */
Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)
{
	*this = toCopy;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

/* Member Function */
void Cat::makeSound() const
{
	std::cout << "The cat goes meow" << std::endl;	
}

/* Operator */
Cat& Cat::operator=(const Cat& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}


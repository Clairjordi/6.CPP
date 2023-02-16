/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:19:15 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/16 13:33:32 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* Constructor and Destructor */
Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& toCopy) : AAnimal(toCopy)
{
	_brain = new Brain();
	*this = toCopy;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
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
	{
		_type = toCopy._type;
		*_brain = *toCopy._brain;
	}
	return (*this);
}


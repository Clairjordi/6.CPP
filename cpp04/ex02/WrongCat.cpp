/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:38:53 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 18:57:19 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* Constructor and Destructor */
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& toCopy) : WrongAnimal(toCopy)
{
	*this = toCopy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/* Member Function */
void WrongCat::makeSound() const
{
	std::cout << "The wrong cat goes meow too, because it's a cat after all" << std::endl;
}

/* Operator */
WrongCat& WrongCat::operator=(const WrongCat& toCopy)
{
	if (this != &toCopy)
		_type = toCopy._type;
	return (*this);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:00:44 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 16:38:05 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* Constructor and Destructor */
Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Eureka, it's a good idea";
}

Brain::Brain(const Brain& toCopy)
{
	*this = toCopy;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

/* Member Function */


/* Operator */
Brain& Brain::operator=(const Brain& toCopy)
{
	if (this != &toCopy)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = toCopy._ideas[i];
	}
	return (*this);
}


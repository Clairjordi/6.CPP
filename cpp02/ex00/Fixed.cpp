/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:59:48 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/09 17:46:20 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;

Fixed::Fixed(void) : _fixedComma(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		_fixedComma = toCopy.getRawBits();
	return (*this);	
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedComma;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedComma = raw;
}





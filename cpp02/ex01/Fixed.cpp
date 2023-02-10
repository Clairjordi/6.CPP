/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:59:48 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/09 17:49:26 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;


Fixed::Fixed(void) : _fixedComma(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedComma = i * ( 1 << _bit);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;

	_fixedComma = roundf(f * (1 << _bit));
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
	return _fixedComma;
}

void Fixed::setRawBits(const int raw)
{
	_fixedComma = raw;
}

float Fixed::toFloat() const
{
	float _f;

	_f = (float)_fixedComma / (1 << _bit);
	return (_f);
}

int Fixed::toInt() const
{
	int i;

	i = _fixedComma >> _bit;
	return (i);
}


std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

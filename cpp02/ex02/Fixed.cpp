/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:59:48 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/10 12:09:58 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;

//static declaration
Fixed Fixed::min(Fixed & ref1,Fixed & ref2)
{
	if (ref1 > ref2)
		return (ref2.toFloat());
	return (ref1.toFloat());
}

Fixed Fixed::min(const Fixed & ref1, const Fixed & ref2)
{
	if (ref1 > ref2)
		return (ref2.toFloat());
	return (ref1.toFloat());
}

Fixed Fixed::max(Fixed & ref1,Fixed & ref2)
{
	if (ref1 < ref2)
		return (ref2.toFloat());
	return (ref1.toFloat());
}

Fixed Fixed::max(const Fixed & ref1, const Fixed & ref2)
{
	if (ref1 < ref2)
		return (ref2.toFloat());
	return (ref1.toFloat());
}


//constructors, destructor
Fixed::Fixed(void) : _fixedComma(0) 
{

}

Fixed::Fixed(const int i)
{
	_fixedComma = i * ( 1 << _bit);
}

Fixed::Fixed(const float f)
{
	_fixedComma = roundf(f * (1 << _bit));
}

Fixed::Fixed(const Fixed& toCopy)
{
	*this = toCopy;
	return ;
}

Fixed& Fixed::operator=(const Fixed & rhs)
{
	if (this != &rhs)
		_fixedComma = rhs.getRawBits();
	return (*this);	
}

Fixed::~Fixed(void)
{

}


//operators
bool Fixed::operator>(const Fixed & rhs) const
{
	return (_fixedComma > rhs._fixedComma);
}

bool Fixed::operator<(const Fixed & rhs) const
{
	return (_fixedComma < rhs._fixedComma);
}

bool Fixed::operator>=(const Fixed & rhs) const
{
	return (_fixedComma >= rhs._fixedComma);
}

bool Fixed::operator<=(const Fixed & rhs) const
{
	return (_fixedComma <= rhs._fixedComma);
}

bool Fixed::operator==(const Fixed & rhs) const
{
	return (_fixedComma == rhs._fixedComma);
}

bool Fixed::operator!=(const Fixed & rhs) const
{
	return (_fixedComma != rhs._fixedComma);
}

Fixed Fixed::operator+(const Fixed & rhs) const
{
	Fixed number;

	number._fixedComma = _fixedComma + rhs._fixedComma;

	return number;
}

Fixed Fixed::operator-(const Fixed & rhs) const
{
	Fixed number;

	number._fixedComma = _fixedComma - rhs._fixedComma;

	return number;
}

Fixed Fixed::operator*(const Fixed & rhs) const
{
	Fixed number;

	number._fixedComma = _fixedComma * rhs._fixedComma;
	number._fixedComma = number._fixedComma >> _bit;

	return number;
}

Fixed Fixed::operator/(const Fixed & rhs) const
{
	Fixed number;
	if (rhs._fixedComma == 0)
	{
		std::cerr << "Division by zero is undefined" << std::endl;
		return (number);
	}
	float f;

	f = (float)_fixedComma / (float)rhs._fixedComma;
	number._fixedComma = roundf(f * (1 << _bit));

	return number;
}

Fixed & Fixed::operator++()
{
	_fixedComma++;
	return (*this);
}

Fixed Fixed::operator++(int i)
{
	(void) i;
	Fixed number = *this;

	_fixedComma++;
	return number;
}

Fixed & Fixed::operator--()
{
	_fixedComma--;
	return (*this);
}

Fixed Fixed::operator--(int i)
{
	(void) i;
	Fixed number = *this;

	_fixedComma--;
	return number;
}


//Functions
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

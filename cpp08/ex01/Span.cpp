/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:23:44 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/12 19:24:26 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Constructor and Destructor */
Span::Span(void)
{
}

Span::Span(unsigned int n)
{
	if (n >= std::numeric_limits<unsigned int>::max() && n <= std::numeric_limits<unsigned int>::min())
		throw std::runtime_error("Out of range");
	_n = n;
}

Span::Span(const Span& toCopy)
{
	*this = toCopy;
}

Span::~Span(void)
{
}

/* Member Function */
void Span::addNumber(int number)
{
	if (_array.size() > _n)
		throw std::runtime_error("Span is full");
	_array.push_back(number);
}

void Span::addMultNumber(int size, int *intArray)
{
	if (size == 0)
		return ;
	if (_array.size() > _n)
		throw std::runtime_error("Span is full");

	if (intArray == 0 && size != 0)
	{

		for (int i = 0; i < size; i++)
			_array.push_back(i + 1);
		return ;
	}
	for (int i = 0; i < size; i++)
		_array.push_back(intArray[i]);
}

// unsigned int Span::shortestSpan() const
// {
//
// }	
//
// unsigned int Span::longestSpan() const
// {
//
// }

std::vector<int> Span::getArray() const
{
	return _array;
}

/* Operator */
Span& Span::operator=(const Span& toCopy)
{
	if (this != &toCopy)
		_n = toCopy._n;
	return *this;
}

std::ostream &  operator<<(std::ostream & o, const Span & i)
{
	 std::vector<int>::iterator it;
	 std::vector<int> array = i.getArray();
	for(it = array.begin(); it != array.end(); ++it)
	{
		o << *it << " ";
	}
	return o;
}

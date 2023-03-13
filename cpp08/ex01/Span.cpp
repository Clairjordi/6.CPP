/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:23:44 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/13 16:53:09 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>

/* Constructor and Destructor */
Span::Span(void)
{
}

Span::Span(unsigned int n) : _n(n)
{
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

	if (size == 0 || intArray == 0)
		return ;
	if (_array.size() + size > _n)
		throw std::runtime_error("Span is full");

	_array.insert(_array.end(), intArray, intArray + size);
}

unsigned int Span::shortestSpan() const
{
	if (_array.size() < 2)
		throw std::runtime_error("Distance calculation impossible");

	std::vector<int> tmpArray = _array;
	std::sort(tmpArray.begin(), tmpArray.end());

	unsigned int dist = std::numeric_limits<unsigned int>::max();
	unsigned int oldDist = 0;
	for (unsigned long i = 0; i < tmpArray.size() - 1; i++)
	{
		oldDist = tmpArray[i + 1] - tmpArray[i];
		if (oldDist < dist)
			dist = oldDist;
	}
	return dist;
}	

unsigned int Span::longestSpan() const
{
	if (_array.size() < 2)
		throw std::runtime_error("Distance calculation impossible");

	std::vector<int> tmpArray = _array;
	std::sort(tmpArray.begin(), tmpArray.end());

	unsigned int dist = tmpArray.back() - tmpArray.front();
	return dist;

}

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

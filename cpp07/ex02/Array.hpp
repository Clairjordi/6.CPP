/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:07:37 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/10 18:16:04 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n); 
		Array(const Array & tocopy);
		Array & operator=(const Array & toCopy);
		~Array();

		T & operator[](unsigned int number);
		unsigned int size() const; // getter

	private:
		class badNumber: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		T *_array;
		unsigned int _n;
};

template<typename T>
/* Constructor and Destructor */
Array<T>::Array(void) : _array(NULL), _n(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
	if (_n == 0)
		_array = NULL;
	_array = new T[_n]();
}

template<typename T>
Array<T>::Array(const Array& toCopy)
{
	_array = NULL;
	*this = toCopy;
}

template<typename T>
Array<T>::~Array(void)
{
	if (_array)
		delete [] _array;
}

/* Member Function */
template<typename T>
unsigned int	Array<T>::size() const
{
	return (_n);
}

template<typename T>
const char* Array<T>::badNumber::what() const throw()
{
	return "Bad index array";
}

/* Operator */
template<typename T>
T & Array<T>::operator[](unsigned int number)
{
	if (number >= _n)
		throw badNumber();
	return _array[number];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& toCopy)
{
	if (this != &toCopy)
	{
		if (_array)
			delete [] _array;
		_array = new T[toCopy._n]();
		for (unsigned int i = 0; i < toCopy._n; i++)
			_array[i] = toCopy._array[i];
		_n = toCopy._n;
	}
	return *this;
}

#endif

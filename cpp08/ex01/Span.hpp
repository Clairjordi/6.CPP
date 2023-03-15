/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:23:44 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/14 15:19:59 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span & tocopy);
		Span & operator=(const Span & toCopy);
		~Span();

		void addNumber(int number); //setter
		void addMultNumber(int size, int *intArray); //setter 
		std::vector<int> getArray() const; // getter
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

	private:
		Span();
		unsigned int _n;
		std::vector<int> _array;
};

std::ostream & operator<<(std::ostream & o, const Span & i);

#endif

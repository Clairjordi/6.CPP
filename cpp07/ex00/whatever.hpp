/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:08:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/11 12:40:17 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template< typename T >
void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template< typename T >
T const & min(const T & x, const T & y)
{
	return (x < y ? x : y);
}

template< typename T >
T const & max(const T & x, const T & y)
{
	return (x > y ? x : y);
}

#endif

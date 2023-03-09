/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:08:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/09 18:36:01 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


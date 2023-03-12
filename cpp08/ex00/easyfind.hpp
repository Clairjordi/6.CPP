/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:50:37 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/12 17:22:09 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <list>

template <typename T>
void easyfind(T container, int n)
{
	try{
		typename T::iterator it = find(container.begin(), container.end(), n);
		if (it == container.end())
			throw std::runtime_error("Element not found : ");
		std::cout << "Element found : " << n << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "ERROR: " << e.what() << n << std::endl; 
	}
}

#endif

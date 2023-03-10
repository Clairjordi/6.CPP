/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/10 14:55:50 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::cout << "Test with array of string :" << std::endl;
	{
		std::string tab[] = {"A", "lovely", "little", "cat"};
		int size = sizeof(tab)/sizeof(tab[0]);
		iter(tab, size, &display);
	}
	std::cout << std::endl;
	std::cout << "Test with array of int :" << std::endl;
	{
		int tab[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		int size = sizeof(tab)/sizeof(tab[0]);
		iter(tab, size, &display);
	}
	std::cout << std::endl;
	std::cout << "Test with array of char :" << std::endl;
	{
		char tab[] = {'H', 'e', 'l', 'l', 'o'};
		int size = sizeof(tab)/sizeof(tab[0]);
		iter(tab, size, &display);
	}
	std::cout << std::endl;
	std::cout << "Test with array of float :" << std::endl;
	{
		float tab[] = {3.14f, 78.369f, 4561.69f};
		int size = sizeof(tab)/sizeof(tab[0]);
		iter(tab, size, &display);
	}
	return 0;
}

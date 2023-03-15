/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/14 15:22:16 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "~~~~~~~~~~~Test with container vector ~~~~~~~~"<< std::endl;
	std::cout << std::endl;
	{
		std::vector<int> intArray;
		intArray.assign(2, 35);
		for (int i = 0; i < 4; i++)
			intArray.push_back(i + 1);
		for (std::vector<int>::iterator it = intArray.begin(); it != intArray.end(); ++it) 
			std::cout << *it << " ";
		std::cout << std::endl;
		easyfind(intArray, 35);
		easyfind(intArray, 5);
	}
	std::cout << "~~~~~~~~~~~Test with container list ~~~~~~~~"<< std::endl;
	std::cout << std::endl;
	{
		std::list<int> intList;
		for (int i = 0; i < 4; i++)
			intList.push_back(i + 8);
		for (std::list<int>::iterator it = intList.begin(); it != intList.end(); ++it) 
			std::cout << *it << " ";
		std::cout << std::endl;
		easyfind(intList, 2);
		easyfind(intList, 10);
	}
	return 0;
}

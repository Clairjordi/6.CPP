/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:27:40 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/22 16:03:13 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main()
{
	Phonebook	phoneBook;
	std::string str;

	while (true)
	{
		std::cout << ">enter a command (ADD, SEARCH or EXIT) : ";
		if ( getline(std::cin, str) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
		if (str == "ADD")
			phoneBook.get_data();
		else if (str == "SEARCH")
			phoneBook.display_phonebook();
		else if (str == "EXIT")
			exit(0);
	}
	return (0);
}

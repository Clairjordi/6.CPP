/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:44:51 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/23 12:06:39 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() 
{
	_index = -1;
	_nb_contact = 0;
}

void Phonebook::get_data()	
{
	_index++;
	if (_index > 7)
		_index = 0;
	_contact[_index].add_contact();
	if (_nb_contact < 8)
		_nb_contact++;
}

int	Phonebook::index_is_valid(std::string str_index)
{
	if (str_index.size() > 1)
	{
		std::cout << "Enter a valid index" << std::endl;
		return (1);
	}
	if (isdigit(str_index[0]) == false)
	{
		std::cout << "Enter a valid index" << std::endl;
		return (1);
	}
	if (str_index[0] - '0' < 0 || str_index[0] - '0' > 7)
	{
		std::cout << "Enter a valid index" << std::endl;
		return (1);
	}
	if (str_index[0] - '0' > _nb_contact - 1)
	{
		std::cout << "Enter an existing index" << std::endl;
		return (1);
	}
	return (0);
}

void Phonebook::info_contact()
{
	std::string str;

	do
	{
		std::cout << "Enter the contact's index you want : ";
		if (getline(std::cin, str) == NULL)
		{
			std::cout << std::endl;
			exit (0);
		}

	}while (str == "" || index_is_valid(str) != 0);
	_contact[str[0] - '0'].display_info_contact();	
}

void Phonebook::display_phonebook()
{
	std::cout << "*********************************************" << std::endl;
	std::cout << "*     index| firstname|  lastname|  nickname*" << std::endl;
	std::cout << "*********************************************" << std::endl;
	if (_nb_contact == 0)
		return ;
	for (int i = 0 ; i < _nb_contact ; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		_contact[i].display_line_phonebook();
	}
	info_contact();
}

Phonebook::~Phonebook()
{

}

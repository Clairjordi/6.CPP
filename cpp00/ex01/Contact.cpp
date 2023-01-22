/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:45:41 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/22 16:50:11 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
{
	
}

int	Contact::phonenumber_is_valid()
{
	for (int i = 0; _phonenumber[i] ; i++)
	{
		if (isdigit(_phonenumber[i]) == false)
		{
			std::cout << "Please, enter a digit" << std::endl;
			return (1);
		}
	}
	if (_phonenumber.size() != 10)
	{
		std::cout << "Please, enter a valid telephone number" << std::endl;
		return (1);
	}
	return (0);
}

void Contact::add_contact()
{
	do
	{
		std::cout << "enter first name: ";
		if (getline(std::cin, _firstname) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
	}while (_firstname == "");
	do
	{
		std::cout << "enter last name: ";
		if (getline(std::cin, _lastname) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
	}while (_lastname == "");
	do
	{
		std::cout << "enter nickname: ";
		if (getline(std::cin, _nickname) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
	}while (_nickname == "");
	do
	{
		std::cout << "enter phone number: ";
		if (getline(std::cin, _phonenumber) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
	}while (_phonenumber == "" || phonenumber_is_valid() != 0);
	do
	{
		std::cout << "enter darkest secret: ";
		if (getline(std::cin, _secret) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
	}while (_secret == "");
}

std::string Contact::short_cut_data(std::string data)
{
	if (data.size() > 10) 
		data = data.substr(0, 9) + ".";
	return (data);

}

void Contact::display_line_phonebook(void)
{
	std::cout << "|" << std::setw(10) << short_cut_data(_firstname);
	std::cout << "|" << std::setw(10) << short_cut_data(_lastname);
	std::cout << "|" << std::setw(10) << short_cut_data(_nickname);
	std::cout << "|" << std::endl;
}

void Contact::display_info_contact()
{
	std::cout << _firstname << std::endl;
	std::cout << _lastname << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << _phonenumber << std::endl;
	std::cout << _secret << std::endl;
}

Contact::~Contact()
{

}

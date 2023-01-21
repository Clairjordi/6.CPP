/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:45:41 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/21 19:12:55 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
{
	
}

std::string	Contact::getfirstname()
{
	return _firstname;
}

std::string	Contact::getlastname()
{
	return _lastname;
}
std::string	Contact::getnickname()
{
	return _nickname;
}

std::string	Contact::getphonenumber()
{
	return _phonenumber;
}

std::string	Contact::getsecret()
{
	return _secret;
}

void Contact::add_contact()
{
	std::string data;
	
	do
	{
		std::cout << "enter first name: ";
		getline(std::cin, data);
		if (getline(std::cin, data) == NULL)
		{
			std::cout << std::endl;
			exit(0);
		}
		_firstname = data;
	}while (_firstname == ""); // fct pour checker si string vide
	std::cout << _firstname << std::endl;
	// do
	// {
	// 	std::cout << "enter last name: ";
	// 	if (getline(std::cin, data) == NULL)
	// 	{
	// 		std::cout << std::endl;
	// 		exit(0);
	// 	}
	// 	_firstname = data;
	// }while (_firstname == "");

}

Contact::~Contact()
{

}

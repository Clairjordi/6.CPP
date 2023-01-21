/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:44:51 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/21 19:11:01 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() 
{
	_index = 0;
}

void Phonebook::get_data()	
{
	_index++;
	if (_index > 8)
		_index = 0;
	_contact[_index].add_contact();
}

Phonebook::~Phonebook()
{

}

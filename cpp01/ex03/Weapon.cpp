/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:10:14 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 15:51:39 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type)
{

}

const std::string& Weapon::getType() const 
{
	return (_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	
}

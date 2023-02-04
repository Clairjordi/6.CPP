/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:37:37 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 16:48:03 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


//faire la gestion d'erreur pour une  Weapon vide

HumanB::HumanB(std::string name) : _name(name)
{

}

void HumanB::setWeapon(Weapon &type)
{
	this->_weaponType = &type;
}

void HumanB::attack()
{
	
	std::cout << this->_name << " attacks with their " << this->_weaponType->getType() << std::endl;
}

HumanB::~HumanB()
{

}

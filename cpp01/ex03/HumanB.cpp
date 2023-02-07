/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:37:37 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/07 11:12:04 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weaponType(NULL)
{
	
}

void HumanB::setWeapon(Weapon &type)
{
	this->_weaponType = &type;
}

void HumanB::attack() const
{
	if (this->_weaponType == NULL)
		std::cout << this->_name << " attacks with her hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weaponType->getType() << std::endl;
}

HumanB::~HumanB()
{

}

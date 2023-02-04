/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:36:13 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 15:55:28 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : _name(name), _weaponType(type)
{

}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weaponType.getType() << std::endl;
}

HumanA::~HumanA()
{

}

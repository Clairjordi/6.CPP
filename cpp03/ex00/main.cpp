/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:03 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/11 11:17:13 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap bob("Boby");
	ClapTrap julie("Juju");


	std::cout << std::endl;
	bob.attack(julie.getName());
	julie.takeDamage(bob.getAttackDamage());
	julie.beRepaired(5);

	std::cout << std::endl;
	julie.attack(bob.getName());

	std::cout << std::endl;
	return 0;
}

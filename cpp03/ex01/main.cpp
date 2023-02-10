/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:03 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/10 19:13:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap Bob("Boby");
	ClapTrap Julie("Juju");
	ScavTrap Robot("Wall·e");
	ScavTrap Android("Erica");

	std::cout << std::endl;
	Robot.attack(Bob.getName());
	Bob.takeDamage(Robot.getAttackDamage());
	Bob.beRepaired(10);

	std::cout << std::endl;
	Bob.attack(Julie.getName());
	Julie.takeDamage(Bob.getAttackDamage());
	Julie.beRepaired(5);

	std::cout << std::endl;

	Android.attack(Robot.getName());
	Robot.takeDamage(Android.getAttackDamage());
	Android.beRepaired(30);
	Robot.guardGate();

	std::cout << std::endl;
	return 0;
}

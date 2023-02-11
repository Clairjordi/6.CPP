/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:00:03 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/11 12:13:58 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap bob("Boby");
	ScavTrap robot("Wall·e");
	ScavTrap android("Erica");
	FragTrap toto("Tutur");

	std::cout << std::endl;
	robot.attack(bob.getName());
	bob.takeDamage(robot.getAttackDamage());
	bob.beRepaired(10);

	std::cout << std::endl;
	toto.attack(android.getName());
	android.takeDamage(toto.getAttackDamage());
	toto.beRepaired(2000);
	toto.highFivesGuys();

	std::cout << std::endl;

	android.attack(robot.getName());
	robot.takeDamage(android.getAttackDamage());
	android.beRepaired(30);
	robot.guardGate();

	std::cout << std::endl;
	return 0;
}

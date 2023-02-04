/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:26:39 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 11:58:54 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie;
	zombie = newZombie("Cl");
	randomChump("Bob");

	delete (zombie);
	return (0);	
}

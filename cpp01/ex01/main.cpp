/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:26:39 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/06 18:39:34 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie;

	zombie = zombieHorde(2, "Walkers");
	for (int i = 0; i < 2; i++)
		zombie[i].announce();

	delete [] zombie;
	return (0);	
}

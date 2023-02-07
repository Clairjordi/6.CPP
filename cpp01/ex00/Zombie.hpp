/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:44:28 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/06 18:44:23 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie 
{
	public:
		Zombie(std::string name);
		~Zombie();

	private:
		void announce(void);
		std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif

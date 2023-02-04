/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:36:47 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 16:45:25 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CPP
# define HUMANB_CPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &type);
	private:
		std::string _name;
		Weapon *_weaponType;
		
};

#endif

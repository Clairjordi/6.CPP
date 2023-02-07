/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:33:51 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/07 11:12:31 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& type);
		~HumanA();
		void attack() const;
		
	private:
		std::string _name;
		Weapon& _weaponType;	
};

#endif

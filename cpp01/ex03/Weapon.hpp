/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:09:51 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 15:51:45 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CPP
# define WEAPON_CPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const;
		void setType(std::string type);

	private:
		std::string _type;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:30 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 16:31:36 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice & toCopy);
		Ice & operator=(const Ice & toCopy);
		virtual ~Ice();

		virtual Ice* clone() const;
		virtual void use(ICharacter & target);

	private:

};

#endif

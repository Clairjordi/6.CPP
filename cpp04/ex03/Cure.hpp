/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:59:30 by clorcery          #+#    #+#             */
/*   pdated: 2023/02/15 19:31:13 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure & toCopy);
		Cure & operator=(const Cure & toCopy);
		virtual ~Cure();

		virtual Cure* clone() const;
		virtual void use(ICharacter & target);

	private:

};

#endif

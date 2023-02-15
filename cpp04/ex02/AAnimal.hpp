/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:16 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 18:54:47 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal & toCopy);
		AAnimal & operator=(const AAnimal & toCopy);
		virtual ~AAnimal();

		std::string getType() const;

		virtual void makeSound() const = 0;

	protected:
		std::string _type;
};

#endif

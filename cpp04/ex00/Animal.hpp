/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:21:16 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 14:16:26 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal & toCopy);
		Animal & operator=(const Animal & toCopy);
		virtual ~Animal();

		std::string getType() const;

		virtual void makeSound() const;

	protected:
		std::string _type;
};

#endif

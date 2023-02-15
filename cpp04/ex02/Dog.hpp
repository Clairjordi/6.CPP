/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:51:47 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 18:58:53 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog & toCopy);
		Dog & operator=(const Dog & toCopy);
		virtual ~Dog();

		virtual void makeSound() const;	

	private:
		Brain* _brain;
};

#endif

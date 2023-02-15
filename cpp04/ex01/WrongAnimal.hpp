/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:47:56 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 17:15:49 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal & toCopy);
		WrongAnimal & operator=(const WrongAnimal & toCopy);
		~WrongAnimal();

		void makeSound() const;

	protected:
			std::string _type;

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:17:23 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 15:52:16 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main()
{

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "(dog)it's a " << dog->getType() << std::endl;
	std::cout << "(cat)it's a " << cat->getType() << std::endl;

	dog->makeSound(); 
	cat->makeSound();

	std::cout << std::endl;
	delete cat;
	delete dog;

	std::cout << std::endl;
	AAnimal** tabAnimal = new AAnimal*[4]();
	for (int i = 0; i < 2; i++)
		tabAnimal[i] = new Dog();
	for (int i = 2; i < 4; i++)
		tabAnimal[i] = new Cat();

	std::cout << std::endl;
	for (int i = 0; i < 4; i++) 
		tabAnimal[i]->makeSound();
	std::cout << std::endl;
	for (int i = 4; i >= 0; i--)
		delete tabAnimal[i];
	delete [] tabAnimal;

	return 0;
}

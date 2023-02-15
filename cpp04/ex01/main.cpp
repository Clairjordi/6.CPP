/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:17:23 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 18:16:33 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "(dog)it's a " << dog->getType() << std::endl;
	std::cout << "(cat)it's a " << cat->getType() << std::endl;
	std::cout << "(animal)it's " << animal->getType() << std::endl;

	dog->makeSound(); 
	cat->makeSound();
	animal->makeSound();

	std::cout << std::endl;
	delete cat;
	delete dog;
	delete animal;


	std::cout << std::endl;
	Animal** tabAnimal = new Animal*[4]();
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

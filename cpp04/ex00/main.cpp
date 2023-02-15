/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:17:23 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 18:59:34 by clorcery         ###   ########.fr       */
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
	const Animal* copy(cat);
	const WrongAnimal* helloKitty = new WrongCat();

	std::cout << std::endl;
	std::cout << "(dog)it's a " << dog->getType() << std::endl;
	std::cout << "(cat)it's a " << cat->getType() << std::endl;
	std::cout << "(animal)it's " << animal->getType() << std::endl;
	std::cout << "(cat's copy)it's a " << copy->getType() << std::endl;

	dog->makeSound(); 
	cat->makeSound();
	animal->makeSound();
	std::cout << "It's a cat so animal sounds is : ";
	copy->makeSound();

	std::cout << std::endl;
	helloKitty->makeSound();

	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete helloKitty;
	return 0;
}

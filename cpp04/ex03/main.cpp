/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:40:43 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 23:43:21 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		MateriaSource* obj = new MateriaSource();
		MateriaSource* src = new MateriaSource(*obj);

		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

	
		Character* point = new Character("me");
		Character* me = new Character(*point);

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);	
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		Character* student = new Character("Thibaud");

		me->use(0, *student);
		me->use(1, *student);
		me->use(2, *student);
		me->use(3, *student);
		me->use(4, *student);

		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		me->unequip(4);
		
		Character* lol = new Character(*me);
		lol->use(0, *student);
		lol->use(1, *student);

		delete src;
		delete me;
		delete tmp;
		delete student;
		delete obj;
		delete point;
		delete lol;
	}
	std::cout << std::endl;
	{
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		MateriaSource* dest = new MateriaSource(*src);
	
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = dest->createMateria("ice");
		me->equip(tmp);
		tmp = dest->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		delete bob;
		delete me;
		delete dest;
		delete src;

	}
	return 0;
}


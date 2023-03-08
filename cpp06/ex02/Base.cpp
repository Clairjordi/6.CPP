/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:00:18 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/01 19:52:43 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* Destructor */
Base::~Base(void)
{
}

/* Function */
Base * generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "The type is : A class" << std::endl;
			return new A;
		case 1:
			std::cout << "The type is : B class" << std::endl;
			return new B;
		case 2:
			std::cout << "The type is : C class" << std::endl;
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a != NULL)
	{
		std::cout << "<Ptr> The type is : A class" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B *>(p);
	if (b != NULL)
	{
		std::cout << "<Ptr> The type is : B class" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C *>(p);
	if (c != NULL)
	{
		std::cout << "<Ptr> The type is : C class" << std::endl;
		return ;
	}
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "<Ref> The type is : A class" << std::endl;
	}
	catch(std::exception &e){}

	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "<Ref> The type is : B class" << std::endl;
	}
	catch(std::exception &e){}

	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "<Ref> The type is : C class" <<std::endl;
	}
	catch(std::exception &e){}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:03:54 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/06 17:58:10 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	_tabLevel[0] = "DEBUG";
	_tabLevel[1] = "INFO";
	_tabLevel[2] = "WARNING";
	_tabLevel[3] = "ERROR";
}

void Harl::complain(std::string level)
{
	int i;
	for(i = 0; i < 4; i++)
	{
		if (_tabLevel[i].compare(level) == 0)
			break ; 
	}

	switch (i)
	{
		case 0:
		{
			debug();
			__attribute__ ((fallthrough));
		}
		case 1:
		{
			info();
			__attribute__ ((fallthrough));
		}
		case 2:
		{
			warning();
			__attribute__ ((fallthrough));
		}
		case 3:
		{
			error();
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void )
{	
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

Harl::~Harl()
{

}

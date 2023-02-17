/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:16:20 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/17 20:33:02 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{	
		Bureaucrat HumanA("New Employee", 150);
		std::cout << HumanA << std::endl;
		HumanA.gradeLow();
		std::cout << HumanA << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{	
		Bureaucrat HumanA("PDG", 1);
		std::cout << HumanA << std::endl;
		HumanA.gradeUp(1);
		std::cout << HumanA << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{	
		Bureaucrat HumanA("Mylene", 50);
		std::cout << HumanA << std::endl;
		HumanA.gradeUp(20);
		std::cout << HumanA << std::endl;
		HumanA.gradeLow(10);
		std::cout << HumanA << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

}

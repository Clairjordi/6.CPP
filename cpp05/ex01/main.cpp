/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:16:20 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/17 20:41:05 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{	
		Bureaucrat humanA("New Employee", 150);
		std::cout << humanA << std::endl;
		std::cout << "New Employee's grade low to 1 : ";
		humanA.gradeLow(1);
		std::cout << humanA << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{	
		Bureaucrat humanA("PDG", 1);
		std::cout << humanA << std::endl;
		std::cout << "PDG's grade up to 1 : ";
		humanA.gradeUp(1);
		std::cout << humanA << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{	
		Bureaucrat humanA("Mylene", 50);
		std::cout << humanA << std::endl;
		std::cout << "Mylene's grade up to 20 : ";
		humanA.gradeUp(20);
		std::cout << humanA << std::endl;
		std::cout << "Mylene's grade low to 10 : ";
		humanA.gradeLow(10);
		std::cout << humanA << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	try
	{	
		Bureaucrat humanA("Specialist", 10);
		std::cout << humanA << std::endl;
		Form cerfa("Cerfa 42", 9, 5);
		std::cout << cerfa << std::endl;
	
		std::cout << std::endl;
		humanA.signForm(cerfa);
		std::cout << cerfa << std::endl;

		humanA.gradeUp(1);
		std::cout << humanA << std::endl;
		humanA.signForm(cerfa);
		std::cout << cerfa << std::endl;

	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	try
	{	
		Bureaucrat humanA("Juju", 10);
		std::cout << humanA << std::endl;
		Form cerfa("Jus de carotte", 10, 5);
		std::cout << cerfa << std::endl;
	
		humanA.signForm(cerfa);
		humanA.signForm(cerfa);


	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	try
	{	
		Bureaucrat humanA("Juju", 10);
		Bureaucrat humanB(humanA);
		std::cout << humanB << std::endl;
		Form cerfa("Earth's friend", 142, 5);
		std::cout << cerfa << std::endl;
	
		humanA.signForm(cerfa);
		humanB.signForm(cerfa);

		
	}
	catch(std::exception const & e)
	{
		std::cout << "ERREUR: " << e.what() << std::endl;
	}
}

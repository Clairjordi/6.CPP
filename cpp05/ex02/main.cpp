/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:16:20 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:37:45 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int main()
{
	try
	{
		Bureaucrat humanA("Ludo", 140);
		std::cout << humanA << std::endl;
		ShrubberyCreationForm form("Garden");
		std::cout << form << std::endl;
		std::cout << std::endl;

		humanA.signForm(form);
		humanA.executeForm(form);
		std::cout << form << std::endl;
		humanA.gradeUp(15);
		std::cout << humanA << std::endl;
		humanA.signForm(form);
		humanA.executeForm(form);
	}
	catch(std::exception const & e)
	{
		std::cout << "ERROR: " << e.what() << std::endl; 
	}
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat humanA("Jean René", 40);
		std::cout << humanA << std::endl;
		RobotomyRequestForm form("Wall·e");
		std::cout << form << std::endl;
		std::cout << std::endl;

		humanA.signForm(form);
		humanA.executeForm(form);
		std::cout << form << std::endl;
		humanA.gradeLow(15);
		std::cout << humanA << std::endl;
		humanA.executeForm(form);
	}
	catch(std::exception const & e)
	{
		std::cout << "ERROR: " << e.what() << std::endl; 
	}
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat humanA("President of Tataouine", 2);
		std::cout << humanA << std::endl;
		PresidentialPardonForm form("Naughty boy");
		std::cout << form << std::endl;
		std::cout << std::endl;

		humanA.signForm(form);
		humanA.executeForm(form);
		std::cout << form << std::endl;
	}
	catch(std::exception const & e)
	{
		std::cout << "ERROR: " << e.what() << std::endl; 
	}
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl;
	try
	{
		Bureaucrat humanA("Jojo", 75);
		ShrubberyCreationForm form("bush");
		std::cout << humanA << std::endl;

		humanA.executeForm(form);
	}
	catch(std::exception const & e)
	{
		std::cout << "ERROR: " << e.what() << std::endl; 
	}
}

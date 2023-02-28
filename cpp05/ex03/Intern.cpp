/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:32:45 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:33:17 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

/* Constructor and Destructor */
Intern::Intern(void)
{
}

Intern::Intern(const Intern& toCopy)
{
	*this = toCopy;
}

Intern::~Intern(void)
{
}

/* Member Function */

AForm* Intern::createForm(const std::string target, int i)
{
	if (i == 0)
		return new ShrubberyCreationForm(target);
	if (i == 1)
		return new RobotomyRequestForm(target);
	return new PresidentialPardonForm(target);
	
}


AForm* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	AForm *form;
	std::string tabForm[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (tabForm[i] == nameForm)
		{
			std::cout << "Intern creates " << tabForm[i] << std::endl;
			form = createForm(targetForm, i);
			return form;
		}
	}
	std::cout << "Intern can't create this form because it doesn't exist" << std::endl;
	return NULL;
}

/* Operator */
Intern& Intern::operator=(const Intern& toCopy)
{
	(void) toCopy;
	return *this;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:44:34 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/27 15:40:47 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Constructor and Destructor */
PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) : Form(toCopy)
{
	*this = toCopy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/* Member Function */
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (getSignedForm() == false)
	{
		std::cout << "It's impossible to execute a form didn't signed" << std::endl;
		return ;
	}
	if (getSignedForm() == true && executor.getGrade() <= getExecuteGrade())
	{
		std::cout << executor.getName() << " executed "<< getNameForm() << std::endl;
		std::cout << _target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw GradeTooLowException();
}

/* Operator */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (this != &toCopy)
		_target = toCopy._target;
	return *this;
}


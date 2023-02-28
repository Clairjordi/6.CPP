/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:44:34 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:34:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Constructor and Destructor */
PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy) : AForm(toCopy)
{
	*this = toCopy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/* Member Function */
void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signedGrade)
		_signedForm = true;
	else 
		throw GradeTooLowException();
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (getSignedForm() == false)
	{
		std::cout << "It's impossible to execute a form didn't signed" << std::endl;
		return ;
	}
	if (_signedForm == true && executor.getGrade() <= _executeGrade)
	{
		std::cout << executor.getName() << " executed "<< _name << std::endl;
		std::cout << _target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
	}
	else
		throw GradeTooLowException();
}

/* Operator */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& toCopy)
{
	if (this != &toCopy)
	{
		_target = toCopy._target;
		_signedForm = toCopy._signedForm;
	}
	return *this;
}


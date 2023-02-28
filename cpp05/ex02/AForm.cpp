/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:07:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:22:28 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Constructor and Destructor */
AForm::AForm(void) : _name("noNameForm"), _signedForm(false), _signedGrade(50),_executeGrade(10) 
{
}

AForm::AForm(const std::string name, const int signedGrade, const int executeGrade) : _name(name), _signedForm(false), _signedGrade(signedGrade),_executeGrade(executeGrade)
{
	if (_signedGrade < 1 or _executeGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade > 150 or _executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& toCopy) : _name(toCopy._name), _signedGrade(toCopy._signedGrade), _executeGrade(toCopy._executeGrade)
{
	*this = toCopy;
}

AForm::~AForm(void)
{
}

/* Member Function */
std::string AForm::getNameForm() const
{
	return _name;
}

bool AForm::getSignedForm() const
{
	return _signedForm;
}

int AForm::getSignedGrade() const
{
	return _signedGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() <= _signedGrade)
		_signedForm = true;
	else 
		throw GradeTooLowException();
}

/* Operator */
AForm& AForm::operator=(const AForm& toCopy)
{
	 if (this != &toCopy)
		_signedForm = toCopy._signedForm;
	 return *this;
}

std::ostream & operator<<(std::ostream & o, const AForm & i)
{
	if (i.getSignedForm() == true)
		o << "Form (signed) : " << i.getNameForm() << " needed a bureaucrat's grade " << i.getSignedGrade() << " to sign and a grade " << i.getExecuteGrade() << " to execute it";
	else 
		o << "Form (to be signed) : " << i.getNameForm() << " needs a bureaucrat's grade " << i.getSignedGrade() << " to be sign and a grade " << i.getExecuteGrade() << " to execute it";

	return o;
}

/*Exceptions*/
const char* AForm::GradeTooHighException::what() const throw()
{
	return  "The bureaucrat's grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return  "The bureaucrat's grade is too low";
}


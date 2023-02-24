/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:07:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/24 17:36:55 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructor and Destructor */
Form::Form(void) : _name("noNameForm"), _signedForm(false), _signedGrade(50),_executeGrade(10) 
{
}

Form::Form(const std::string name, const int signedGrade, const int executeGrade) : _name(name), _signedForm(false), _signedGrade(signedGrade),_executeGrade(executeGrade)
{
	if (_signedGrade < 1 or _executeGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade > 150 or _executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& toCopy) : _name(toCopy._name), _signedGrade(toCopy._signedGrade), _executeGrade(toCopy._executeGrade)
{
	*this = toCopy;
}

Form::~Form(void)
{
}

/* Member Function */
const std::string Form::getNameForm() const
{
	return _name;
}

bool Form::getSignedForm() const
{
	return _signedForm;
}

int Form::getSignedGrade() const
{
	return _signedGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signedGrade)
		_signedForm = true;
	else 
		throw GradeTooLowException();
}

/* Operator */
Form& Form::operator=(const Form& toCopy)
{
	 if (this != &toCopy)
		_signedForm = toCopy._signedForm;
	 return *this;
}

std::ostream & operator<<(std::ostream & o, const Form & i)
{
	if (i.getSignedForm() == true)
		o << "Form (signed) : " << i.getNameForm() << " needed a bureaucrat's grade " << i.getSignedGrade() << " to sign and a grade " << i.getExecuteGrade() << " to execute it";
	else 
		o << "Form (to be signed) : " << i.getNameForm() << " needs a bureaucrat's grade " << i.getSignedGrade() << " to be sign and a grade " << i.getExecuteGrade() << " to execute it";

	return o;
}

/*Exceptions*/
const char* Form::GradeTooHighException::what() const throw()
{
	return  "The bureaucrat's grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return  "The bureaucrat's grade is too low";
}


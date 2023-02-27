/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:34 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/27 14:38:10 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* Constructor and Destructor */
Bureaucrat::Bureaucrat(void) : _name("noName"), _grade(150)
{	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy): _name(toCopy._name)
{
	*this = toCopy;
}

Bureaucrat::~Bureaucrat(void)
{
}

/* Member Function */
std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::gradeUp(int N)
{
	if (_grade - N < 1)
		throw GradeTooHighException();
	_grade -= N;

}

void Bureaucrat::gradeLow(int N)
{	
	if (_grade + N > 150)
		throw GradeTooLowException();
	_grade += N;
}

void Bureaucrat::signForm(Form & form) 
{
	Form *formTest = NULL;
	if (&form == formTest)
	{
		std::cout << "This form doesn't exist, so it's impossible to sign" << std::endl; 
		return ;
	}
	if (form.getSignedForm() == true)
	{
		std::cout << "Form " << form.getNameForm() << " is already signed" << std::endl; 
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << "The bureaucrat " << _name << " signed " << form.getNameForm() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "The bureaucrat " << _name << " couldn't sign " << form.getNameForm() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	Form *formTest = NULL;
	if (&form == formTest)
	{
		std::cout << "This form doesn't exist, so it's impossible to execute" << std::endl;
		return ;
	}
	try
	{
		form.execute(*this);
	}
	catch (std::exception const & e)
	{
		std::cout << "The bureaucrat " << _name << " couldn't execute " << form.getNameForm() << " because " << e.what() << std::endl;
	}
}

/* Operator */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy)
{
	if (this != &toCopy)
		_grade = toCopy._grade;
	return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << "The bureaucrat " << i.getName() << " has a grade of "<< i.getGrade();
	return o;
}

/*Exceptions*/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The bureaucrat's grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The bureaucrat's grade is too low";
}

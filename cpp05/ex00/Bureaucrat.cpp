/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:08:34 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/17 16:04:55 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

/* Constructor and Destructor */
Bureaucrat::Bureaucrat(void) : _name("noName"), _grade(150)
{	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)//, _grade(grade)
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
const std::string Bureaucrat::getName() const
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

/* Operator */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy)
{
	if (this != &toCopy)
	{
		_grade = toCopy._grade;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, const Bureaucrat & i)
{
	o << "The bureaucrate " << i.getName() << " has a grade of "<< i.getGrade();
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

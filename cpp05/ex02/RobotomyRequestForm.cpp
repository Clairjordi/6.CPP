/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:44:18 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/27 15:40:58 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Constructor and Destructor */
RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& toCopy) : Form(toCopy)
{
	*this = toCopy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

/* Member Function */

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSignedForm() == false)
	{
		std::cout << "It's impossible to execute a form didn't signed" << std::endl;
		return ;
	}
	if (getSignedForm() == true && executor.getGrade() <= getExecuteGrade())
	{
		std::cout << executor.getName() << " executed "<< getNameForm() << std::endl;
		
		srand (time(NULL));
		if(rand() % 2 == 0)
		{
			std::cout << "rrrrrrr...rrrrrrrr" << std::endl;
			std::cout << _target << " has been successfully robotized 50\% of the time" << std::endl;
		}
		else
			std::cout << _target << " Robotized failed" << std::endl;
	}
	else
		throw GradeTooLowException();
}

/* Operator */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& toCopy)
{
	if (this != &toCopy)
		_target = toCopy._target;
	return *this;
}


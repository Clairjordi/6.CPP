/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:19:59 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:21:42 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Constructor and Destructor */
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm()
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm(toCopy)
{
	*this = toCopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

/* Member Function */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSignedForm() == false)
	{
		std::cout << "It's impossible to execute a form didn't signed" << std::endl;
		return ;
	}
	if (getSignedForm() == true && executor.getGrade() <= getExecuteGrade())
	{
		std::cout << executor.getName() << " executed "<< getNameForm() << std::endl;
		std::string name = _target + "_shrubbery";
		std::ofstream ofs(name.c_str());
		ofs <<	"        /\\            \n"
				"       /\\*\\          \n"
				"      /\\O\\*\\        \n"
				"     /*/\\/\\/\\       \n"
				"    /\\O\\/\\*\\/\\    \n"
				"   /\\*\\/\\*\\/\\/\\  \n"
				"  /\\O\\/\\/*/\\/O/\\  \n"
				"        ||             \n"
				"        ||             \n"
				"        ||             \n"
				"        /\\            \n"
				"       /\\*\\          \n"
				"      /\\O\\*\\        \n"
				"     /*/\\/\\/\\       \n"
				"    /\\O\\/\\*\\/\\    \n"
				"   /\\*\\/\\*\\/\\/\\  \n"
				"  /\\O\\/\\/*/\\/O/\\  \n"
				"        ||             \n"
				"        ||             \n"
				"        ||             \n";
	}
	else
		throw GradeTooLowException();
}

/* Operator */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& toCopy)
{
	if (this != &toCopy)
		_target = toCopy._target;
	return *this;
}


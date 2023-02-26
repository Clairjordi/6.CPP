
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

Form* Intern::createForm(const std::string target, int i)
{
	if (i == 0)
		return new ShrubberyCreationForm(target);
	if (i == 1)
		return new RobotomyRequestForm(target);
	return new PresidentialPardonForm(target);
	
}


Form* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	Form *form;
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


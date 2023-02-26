
#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern & toCopy);
		Intern & operator=(const Intern & toCopy);
		~Intern();
		
		Form* makeForm(std::string nameForm, std::string targetForm);

	private:
		Form* createForm(const std::string target, int i);

};

#endif

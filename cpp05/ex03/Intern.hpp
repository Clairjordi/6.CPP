/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:32:48 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:33:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
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
		
		AForm* makeForm(std::string nameForm, std::string targetForm);

	private:
		AForm* createForm(const std::string target, int i);

};

#endif

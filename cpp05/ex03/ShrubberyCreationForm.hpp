/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:20:00 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:31:47 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm & toCopy);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & toCopy);
		virtual ~ShrubberyCreationForm();

		virtual void beSigned(const Bureaucrat & bureaucrat);

		virtual void execute(Bureaucrat const & executor) const;		

	private:
		std::string _target;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:44:34 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/25 18:05:37 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & toCopy);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & toCopy);
		virtual ~PresidentialPardonForm();

		virtual void beSigned(const Bureaucrat & bureaucrat);

		virtual void execute(Bureaucrat const & executor) const;	

	private:
		std::string _target;
};

#endif

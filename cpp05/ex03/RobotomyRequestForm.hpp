/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:44:19 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/25 17:50:52 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm & toCopy);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & toCopy);
		virtual ~RobotomyRequestForm();

		virtual void beSigned(const Bureaucrat & bureaucrat);

		virtual void execute(Bureaucrat const & executor) const;		

	private:
		std::string _target;

};

#endif

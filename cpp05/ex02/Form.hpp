/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:07:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/25 17:26:17 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int signedGrade, const int executeGrade);
		Form(const Form & toCopy);
		Form & operator=(const Form & toCopy);
		virtual ~Form();

		std::string 	getNameForm() const;
		bool		getSignedForm() const;
		int			getSignedGrade() const;
		int			getExecuteGrade() const;


		virtual void beSigned(const Bureaucrat & bureaucrat) = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;
		

	protected:
		const std::string 	_name;
		bool				_signedForm;
		const int			_signedGrade;
		const int			_executeGrade;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, const Form & i);

#endif

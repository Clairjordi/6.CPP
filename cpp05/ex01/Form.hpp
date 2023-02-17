/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:07:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/17 19:45:07 by clorcery         ###   ########.fr       */
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
		~Form();

		const std::string 	getNameForm() const;
		bool		getSignedForm() const;
		int			getSignedGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat & bureaucrat);
		

	private:
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

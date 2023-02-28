/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:07:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/28 11:16:16 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string name, const int signedGrade, const int executeGrade);
		AForm(const AForm & toCopy);
		AForm & operator=(const AForm & toCopy);
		virtual ~AForm();

		std::string 	getNameForm() const;
		bool		getSignedForm() const;
		int			getSignedGrade() const;
		int			getExecuteGrade() const;


		virtual void beSigned(const Bureaucrat & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		

	private:
		const std::string 	_name;
		bool				_signedForm;
		const int			_signedGrade;
		const int			_executeGrade;

	protected:
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

std::ostream & operator<<(std::ostream & o, const AForm & i);

#endif

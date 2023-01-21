/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:48:57 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/21 19:11:05 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
#include <string>
#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void get_data();
	private:
		//Contact _contact;
		Contact	_contact[8];
		int		_index;
};

#endif

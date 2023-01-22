/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:48:57 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/22 17:07:24 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void get_data();
		void display_phonebook();
		void info_contact();
		int	index_is_valid(std::string str_index);
	private:
		Contact	_contact[8];
		int		_index;
		int		_nb_contact;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:48:57 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/24 16:04:08 by clorcery         ###   ########.fr       */
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

	private:
		int	 	index_is_valid(std::string str_index);
		Contact	_contact[8];
		int		_index;
		int		_nb_contact;
};

#endif

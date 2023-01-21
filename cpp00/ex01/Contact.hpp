/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:28 by clorcery          #+#    #+#             */
/*   Updated: 2023/01/21 19:09:53 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
//# include <iomanip> // pour permettre de decaler a droite - utiliser setw
# include <string>
#include <cstdlib>

class Contact
{
	public:
		Contact(); //constructeur
		~Contact(); //destructeur
		//getters
		std::string	getfirstname();	
		std::string	getlastname();	
		std::string	getnickname();	
		std::string	getphonenumber();	
		std::string	getsecret();	
		//declarations des methodes ou fonctions membres
		void add_contact();
	private:
		//declaration des attributs ou variables manbres
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string	_phonenumber;
		std::string _secret;
};


#endif

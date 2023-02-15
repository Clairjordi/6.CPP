/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:00:44 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/13 18:20:45 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain 
{
	public:
		Brain();
		Brain(const Brain & toCopy);
		Brain & operator=(const Brain & toCopy);		~Brain();

	private:
		std::string _ideas[100];
};

#endif

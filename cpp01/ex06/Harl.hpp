/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:03:09 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/06 17:59:45 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		std::string _tabLevel[5];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif

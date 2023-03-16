/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:46:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/16 13:59:25 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void recupData(std::ifstream & dataFile);


	private:
		BitcoinExchange(const BitcoinExchange & toCopy);
		BitcoinExchange & operator=(const BitcoinExchange & toCopy);
		std::map<std::string, float> _data;

};

#endif

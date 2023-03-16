/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:46:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/16 16:19:34 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <exception>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream & dataFile, std::ifstream & input);
		~BitcoinExchange();


	private:
		BitcoinExchange();
		std::map<std::string, float> _data;
		std::ifstream & _input;
		
		void recupData(std::ifstream & dataFile);
		void checkFile()
		

		BitcoinExchange(const BitcoinExchange & toCopy);
		BitcoinExchange & operator=(const BitcoinExchange & toCopy);

};

#endif

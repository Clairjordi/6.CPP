/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:46:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/17 19:07:08 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <limits>
#include <cmath>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream & dataFile);
		~BitcoinExchange();

		void bitcoinConversion(std::ifstream & input);


	private:
		std::map<std::string, float> _data;
		std::string _errorMsg;
		
		void recupData(std::ifstream & dataFile);
				
		bool checkDate(std::string line, char delimiter);
		bool checkDay(int year, int month, int day);

		bool checkValue(std::string line, char delimiter);
		bool checkFloat(std::string str);

		void operation(std::string line);

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & toCopy);
		BitcoinExchange & operator=(const BitcoinExchange & toCopy);
};

#endif

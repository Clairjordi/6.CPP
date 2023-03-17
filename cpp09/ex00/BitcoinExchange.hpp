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
#include <exception>
//#include <time.h>
#include <ctime>
#include <limits>
#include <cmath>
//#include <cstdlib>
//#include <algorithm>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream & dataFile, std::ifstream & input);
		~BitcoinExchange(); // in private ?


	private:
		BitcoinExchange();
		std::map<std::string, float> _data;
		std::ifstream & _input;
		
		void recupData(std::ifstream & dataFile);
		//void checkFile();
		std::string _errorMsg;
				
		bool checkDate(std::string line, char delimiter);

		bool checkValue(std::string line);
		BitcoinExchange(const BitcoinExchange & toCopy);
		BitcoinExchange & operator=(const BitcoinExchange & toCopy);

};

#endif

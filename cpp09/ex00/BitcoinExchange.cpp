/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:46:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/16 12:40:14 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <sstream>

/* Constructor and Destructor */
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
}

/* Member Function */
void BitcoinExchange::recupData(std::ifstream & dataFile)
{
	std::string line;
	
	while (getline (dataFile, line))
	{
		std::string date;
		float value;
		char comma;
		std::istringstream iss(line);
		std::cout << line << std::endl;
		if (iss >> date >> comma >> value)
			_data[date] = value;
		line.clear();
	}


	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator ite = _data.end();
	for (it =_data.begin() ; it != ite; ++it)
		std::cout << it->first << " " << it->second <<std::endl;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:46:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/16 16:19:34 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Constructor and Destructor */
BitcoinExchange::BitcoinExchange(std::ifstream & dataFile, std::ifstream & input) : _input(input)
{
	checkFile(); // faire ce check au moment de la la recherche pour pouvoir multiplier car l'execution du programme ne s'arrete pas
	recupData(dataFile);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

/* Private Function */
void BitcoinExchange::recupData(std::ifstream & dataFile)
{
	std::string line;
	std::string date;
	float value;
	char delimiteur = ',';
	
	while (getline (dataFile, line))
	{
		std::istringstream iss(line);
		if (getline(iss, date, delimiteur) && iss >> value)
			_data[date] = value;
	}


	// std::map<std::string, float>::iterator it;
	// std::map<std::string, float>::iterator ite = _data.end();
	// for (it =_data.begin() ; it != ite; ++it)
	// 	std::cout << it->first << " " << it->second <<std::endl;
}


void BitcoinExchange::checkFile()
{
	std::string line;

	while (getline(_input, line))
	{
		//verification de la date : Annee-mois-jour (dans cet ordre et separer par des tirets / une fois date correcte verifier )
		//pipe separateur correct
		//verification du nombre = float ou int, pas de negatif, verif des float et des int overflow
		//
	}
}



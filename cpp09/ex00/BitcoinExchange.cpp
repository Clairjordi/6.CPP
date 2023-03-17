/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:46:33 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/17 19:06:35 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Constructor and Destructor */
BitcoinExchange::BitcoinExchange(std::ifstream & dataFile, std::ifstream & input) : _input(input)
{
	recupData(dataFile);
	//checkFile(); // faire ce check au moment de la la recherche pour pouvoir multiplier car l'execution du programme ne s'arrete pas
}

BitcoinExchange::~BitcoinExchange(void)
{
}

/* Private Function */
static bool checkBissextileYear(int year)
{
	if(year % 4 == 0)
    {
        if( year % 100 == 0)
        {
            if ( year % 400 == 0)
				return true;
            else
				return false;
        }
        else
			return true;
    }
    else
		return false;
}

bool BitcoinExchange::checkDate(std::string line, char delimiter)
{
	if (line.compare("date,exchange_rate") == 0)
		return true;

	std::string date;
	size_t pos;
	pos = line.find(delimiter);
	if (pos == std::string::npos)
	{
		_errorMsg = "Error: wrong format, missing value  => " + line;
		return false;
	}
	date = line.substr(0, pos);
	struct tm tm;
	if (strptime(date.c_str(), "%F", &tm) == NULL)
	{
		_errorMsg = "Error: wrong format, invalid date => " + date;
		return false;
	}

	int year, month, day;
	std::istringstream iss(date);
	char dash = '-';

	iss >> year >> dash >> month >> dash >> day;
	if ((year < 0 || year > 9999) || (month < 1 || month > 12))
		return false;
	if (day >= 1 && day <= 31)
	{
		if (month == 2)
		{
			if (day <= 29 && checkBissextileYear(year) == true)
				return true;
			if (day <= 28 && checkBissextileYear(year) == false)
				return true;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30)
				return true;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31)
				return true;
		}
	}
	_errorMsg = "Error: wrong format, invalid date => " + date;
	return false;
}

static bool	checkFloat(std::string str)
{
	std::string::size_type firstPoint = 0;
	bool digit = false;

	for (size_t i = 0; i < str.size() ; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
				return false;
		if (str[i] != '.' && isdigit(str[i]) == false)
			return false;
		if (firstPoint == 0)
			firstPoint = str.find(".", 0);
		if (digit == false && isdigit(str[i]))
			digit = true;
	}
	if (digit == false)
		return false;
	if (firstPoint == std::string::npos)
		return false;
	std::string::size_type otherPoint = str.find(".", firstPoint + 1);
	if (otherPoint != std::string::npos)
		return false;
	return true;
}

static bool checkRange(std::string value, std::string type)
{
	if (type == "i")
	{
		long int num = strtol(value.c_str(), NULL, 10);
		if (num >= 0 && num <= std::numeric_limits<int>::max())
			return true;
	}
	if (type == "f")
	{
		float num = strtof(value.c_str(), NULL);
		if (errno == ERANGE)
			return false;
		if (num >= 0 && num <= std::numeric_limits<float>::max())
			return true;
	}
	return false;
}

bool BitcoinExchange::checkValue(std::string line)
{
	if (line.compare("date,exchange_rate") == 0)
		return true;

	std::string value;
	size_t pos;
	pos = line.find(',');
	value = line.substr(pos + 1);
	if (value == "")
	{
		_errorMsg = "Error: wrong format, missing value  => " + line;
		return false;
	}

	size_t i;
	for (i = 0; i < value.size(); i++)
	{
		if (isdigit(value[i]) == 0)
				break ;
	}
	if (value.size() == i)
	{
	
		if (checkRange(value, "i") == false)
		{
			_errorMsg = "Error: wrong format, invalid value  => " + line;
			return false;
		}
		return true;
	}
	if (checkFloat(value) == false)
	{
		_errorMsg = "Error: wrong format, invalid value  => " + line;
		return false;
	}
	else
	{
		if (checkRange(value, "f") == false)
		{
			_errorMsg = "Error: wrong format, invalid value  => " + line;
			return false;
		}
	}
	//verifier qu'il ai quelque chose apres la virgule
	//verifier si c'est un float ou un int 
	//overflow correspondant pour les max only : Error: too large a number.
	//si negatif : Error: not a positive number.
	return true;
}

void BitcoinExchange::recupData(std::ifstream & dataFile)
{
	std::string line;
	std::string date;
	int value;
	char delimiteur = ',';
	int i = 0;

	while (getline (dataFile, line) && i < 3)
	{
		if (checkDate(line, ',') == true && checkValue(line) == true)
		{
			std::istringstream iss(line);
			if (getline(iss, date, delimiteur) && iss >> value)
				_data[date] = value;
		}
		else
		{
			std::cout << "File data.csv : " << _errorMsg << " - unregistered line " << std::endl;
			_errorMsg = "";
		}
		i++;
	}

//A SUPPRIMER !!!! affichage du contenu de map 
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator ite = _data.end();
	for (it =_data.begin() ; it != ite; ++it)
		std::cout << it->first << " " << it->second <<std::endl;
}


// void BitcoinExchange::checkFile()
// {
// 	std::string line;
//  
//  _errorMsg = "";
// 	while (getline(_input, line))
// 	{
// 		//verification de la date : Annee-mois-jour (dans cet ordre et separer par des tirets / une fois date correcte verifier )
// 		//pipe separateur correct
// 		//verification du nombre = float ou int, pas de negatif, verif des float et des int overflow
// 		//
// 	}
// }



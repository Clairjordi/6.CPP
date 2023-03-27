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
BitcoinExchange::BitcoinExchange(std::ifstream & dataFile)
{
	recupData(dataFile);
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

bool BitcoinExchange::checkDay(int year, int month, int day)
{
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
	return false;
}

bool BitcoinExchange::checkDate(std::string line, char delimiter)
{
	if (line.compare("date,exchange_rate") == 0 || line.compare("date | value") == 0)
		return true;

	std::string date;
	size_t pos;
	pos = line.find(delimiter);
	if (pos == std::string::npos)
	{
		_errorMsg = "bad input  => " + line;
		return false;
	}
	date = line.substr(0, pos);
	struct tm tm;
	if (strptime(date.c_str(), "%F", &tm) == NULL)
	{
		_errorMsg = "bad input => " + date;
		return false;
	}

	int year, month, day;
	std::istringstream iss(date);
	char dash = '-';

	iss >> year >> dash >> month >> dash >> day;
	if ((year < 0 || year > 9999) || (month < 1 || month > 12))
	{
		_errorMsg = "bad input => " + date;
		return false;
	}
	if (delimiter == ' ')
	{
		if (year < 2009)
		{
			_errorMsg = "Bitcoin doesn't exist at this time => " + date;
			return false;
		}
		std::time_t result;
	
		result = std::time(NULL);
		std::tm *now = std::localtime(&result);
		if (tm.tm_year > now->tm_year)
		{
			_errorMsg = "this date is later than today => " + date;
			return false;
		}
		if (tm.tm_year == now->tm_year && tm.tm_mon > now->tm_mon )
		{
			_errorMsg = "this date is later than today => " + date;
			return false;
		}
		if (tm.tm_year == now->tm_year && tm.tm_mon == now->tm_mon && tm.tm_mday > now->tm_mday)
		{
			_errorMsg = "this date is later than today => " + date;
			return false;
		}

	}
	if (checkDay(year, month, day) == true)
		return true;
	_errorMsg = "bad input => " + date;
	return false;
}

bool	BitcoinExchange::checkFloat(std::string str)
{
	std::string::size_type firstPoint = 0;
	bool digit = false;

	for (size_t i = 0; i < str.size() ; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			_errorMsg = "not a positive number.";
			return false;
		}
		if (str[i] != '.' && isdigit(str[i]) == false)
		{
			_errorMsg = "not a number.";
			return false;
		}
		if (firstPoint == 0)
			firstPoint = str.find(".", 0);
		if (digit == false && isdigit(str[i]))
			digit = true;
	}
	if (digit == false)
	{
		_errorMsg = "not a number.";
		return false;
	}
	if (firstPoint == std::string::npos)	
	{
		_errorMsg = "not a number.";
		return false;
	}
	std::string::size_type otherPoint = str.find(".", firstPoint + 1);
	if (otherPoint != std::string::npos)	
	{
		_errorMsg = "not a number.";
		return false;
	}
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

bool BitcoinExchange::checkValue(std::string line, char delimiter)
{
	if (line.compare("date,exchange_rate") == 0 || line.compare("date | value") == 0)
		return true;

	std::string value;
	size_t pos;
	if (delimiter == ' ')
	{
		size_t firstSpace = line.find(delimiter);
		if (line[firstSpace + 1] != '|' || line[firstSpace + 2] == '|')
		{
			_errorMsg = "bad input  => " + line;
			return false;
		}
		pos = line.find(delimiter, firstSpace + 1);
		if (pos == std::string::npos)
		{
			_errorMsg = "bad input  => " + line;
			return false;
		}
	}
	else
		pos = line.find(delimiter);
	value = line.substr(pos + 1);
	if (value == "")
	{
		_errorMsg = "missing value  => " + line;
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
			_errorMsg = "too large a number.";
			return false;
		}
		if (delimiter == ' ')
		{
			if (strtof(value.c_str(), NULL) > 1000)
			{
 				_errorMsg = "too large a number.";
				return false;
			}
		}
		return true;
	}
	if (checkFloat(value) == false)
		return false;
	else
	{
		if (checkRange(value, "f") == false)
		{
			_errorMsg = "too large a number.";
			return false;
		}
	}
	if (delimiter == ' ')
	{
		if (strtof(value.c_str(), NULL) > 1000)
		{
			_errorMsg = "too large a number.";
			return false;
		}
	}
	return true;
}

void BitcoinExchange::recupData(std::ifstream & dataFile)
{
	std::string line;
	std::string date;
	float value;
	char delimiteur = ',';

	while (getline (dataFile, line))
	{
		if (checkDate(line, ',') == true && checkValue(line, ',') == true)
		{
			std::istringstream iss(line);
			if (getline(iss, date, delimiteur) && iss >> value)
				_data[date] = value;
		}
		else
		{
			std::cout << "Error, data.csv : " << _errorMsg << " - unregistered line " << std::endl;
			_errorMsg = "";
		}
	}
}

void BitcoinExchange::operation(std::string line)
{
	if (line.compare("date | value") == 0)
		return ;
	std::string date = line.substr(0, 10);
	float value = atof((line.substr(13).c_str()));
	float result = 0;
	
	std::map<std::string, float>::iterator search;
	search = _data.find(date);
	if (search != _data.end())
	{
		result = value * search->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
		return ;
	}
	search = _data.lower_bound(date);
	if (search == _data.begin())
	{
		std::cout << "Error: date is prior then database" << std::endl;
		return ;
	}
	if (search != _data.begin())
		search--;
	if (search != _data.end())
		result = value * search->second;
	std::cout << date << " => " << value << " = " << result << std::endl;
}


/*Member Function */
void BitcoinExchange::bitcoinConversion(std::ifstream & input)
{
	std::string line;

	while (getline(input, line))
	{
		if (checkDate(line, ' ') == true && checkValue(line, ' ') == true)
			operation(line);
		else
		{
			std::cout << "Error: " << _errorMsg << std::endl;
			_errorMsg = "";
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:55:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/07 19:40:18 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Member Function */

std::string checkPseudoLiterals(std::string literals)
{
	std::string tabLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int i;
	for (i = 0; i < 6; i++)
	{
		if (tabLiterals[i] == literals)
		{
			break ;
		}
	}
	if (i < 3)
		return "f";
	if (i < 6)
		return "d";
	return "";

}

void convertPseudoLitterals(std::string toConvert, std::string pseudoLiterals)
{
	if (pseudoLiterals == "f")
	{
		std::cout << "char : it's impossible" << std::endl; 
		std::cout << "int : it's impossible" << std::endl; 
		std::cout << "float : " << toConvert << std::endl;
		std::string tmp = toConvert.substr(0, toConvert.size() - 1);
		std::cout << "double : " << tmp << std::endl;
	}
	else if (pseudoLiterals == "d")
	{
		std::cout << "char : it's impossible" << std::endl; 
		std::cout << "int : it's impossible" << std::endl; 
		std::cout << "float : " << toConvert + "f" << std::endl;
		std::cout << "double : " << toConvert << std::endl;
	}
}

void convertLiteralsFloatDouble(std::string toConvert, std::string type)
{
	std::cout.setf(std::ios::fixed);
	int idx = toConvert.find(".", 0) + 1;
	int size = toConvert.size() - idx;
	if (type == "f")
	{	
		std::cout.precision(size - 1);

		char *endptr;
		float f = strtof(toConvert.c_str(), &endptr);

		if (f > 127 || f < 0)
			std::cout << "char : it's impossible" << std::endl; 	
		else if (!isprint(f))
			std::cout << "char   : no displayable" << std::endl;
		else 
			std::cout << "char   : " << static_cast<char>(f) << std::endl;

		if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
			std::cout << "int : " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int : it's impossible"  << std::endl;

		std::cout << "float  : " << f << "f" << std::endl;
		std::cout << "double  : " << static_cast<double>(f) << std::endl;
	}
	if (type == "d")
	{	
		std::cout.precision(size);

		char *endptr;
		double d = strtod(toConvert.c_str(), &endptr);
		
		if (d > 127 || d < 0)
			std::cout << "char : it's impossible" << std::endl; 	
		else if (!isprint(d))
			std::cout << "char   : no displayable" << std::endl;
		else 
			std::cout << "char   : " << static_cast<char>(d) << std::endl;

		if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
			std::cout << "int : " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int : it's impossible"  << std::endl;

		if (d <= std::numeric_limits<float>::max() && d >= -std::numeric_limits<float>::max())
			std::cout << "float  : " <<  static_cast<float>(d)<< "f" << std::endl;
		else
			std::cout << "float : it's impossible"  << std::endl;

		std::cout << "double  : " << d << std::endl;
	}
}

void convertLiterals(std::string toConvert, std::string type)
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(1);
	if (type == "c")
	{
		std::cout << "char   : " << toConvert[0] << std::endl;
		std::cout << "int    : " << static_cast<int>(toConvert[0]) << std::endl;
		std::cout << "float  : " << static_cast<float>(toConvert[0]) << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(toConvert[0]) << std::endl;
	}
	if (type == "i")
	{
		int i  = std::atoi(toConvert.c_str());
	
		if (i > 127 || i < 0)
			std::cout << "char : it's impossible" << std::endl; 	
		else if (!isprint(i))
			std::cout << "char   : no displayable" << std::endl;
		else 
			std::cout << "char   : " << static_cast<char>(i) << std::endl;

		std::cout << "int : " << i << std::endl;
		std::cout << "float  : " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double  : " << static_cast<double>(i) << std::endl;
	}
	else
	 	convertLiteralsFloatDouble(toConvert, type);
}

bool checkOverflow(std::string strToConvert, std::string type)
{
	char *endptr;
	double num = strtod(strToConvert.c_str(), &endptr);
	if (errno == ERANGE)
		return false;

	if (type == "i" && num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min())
		return true;
	if (type == "f" && num <= std::numeric_limits<float>::max() && num >= -std::numeric_limits<float>::max())
			return true;
	if (type == "d" && num <= std::numeric_limits<double>::max() && num >= -std::numeric_limits<double>::max())
		return true;
	return false;
}

bool	checkFloatDouble(std::string str)
{
	std::string::size_type firstPoint = 0;

	for (int i = 0; i < str[i] ; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
				i = 1;
		if (str[i + 1] == '\0' && str[i] == 'f')
			break ;
		if (str[i] != '.' && isdigit(str[i]) != true)
			return false;
		if (firstPoint == 0)
			firstPoint = str.find(".", 0);
	}
	if (firstPoint == std::string::npos)
		return false;
	std::string::size_type otherPoint = str.find(".", firstPoint + 1);
	if (otherPoint != std::string::npos)
		return false;
	return true;
}

std::string checkParsing(std::string strToConvert)
{
	if (strToConvert == "")
		return "Bad argument";
	if (strToConvert.size() == 1)
	{
		if (isdigit(strToConvert[0]) == 0)
			return "c";
		return "i";
	}
	if (strToConvert.size() > 1)
	{
		size_t i;
		for (i = 0; i < strToConvert.size(); i++)
		{	
			if (i == 0 && (strToConvert[i] == '+' || strToConvert[i] == '-'))
				i = 1;
			if (isdigit(strToConvert[i]) == 0)
					break ;
		}
		if (i == strToConvert.size())
		{
			if (checkOverflow(strToConvert, "i") == true)
				return "i";
			return "Bad number";
		}
	}
	if (checkFloatDouble(strToConvert) == false)
		return "Bad argument";
	char lastChar = strToConvert[strToConvert.size() - 1];
	if (lastChar == 'f')
	{
		if (checkOverflow(strToConvert, "f") == true)
			return "f";
	}
	else	
		if (checkOverflow(strToConvert, "d") == true)
			return "d";
	return "Bad number";
}

void ScalarConverter::convert(std::string toConvert)
{
	std::string pseudoLiterals = checkPseudoLiterals(toConvert);
	if (pseudoLiterals == "f" || pseudoLiterals == "d")
		convertPseudoLitterals(toConvert, pseudoLiterals);
	else
	{
		std::string type = checkParsing(toConvert);
		if (type.size() == 1)
			convertLiterals(toConvert, type);
		else
			std::cout << type << std::endl;
	}
}	

///////////////////////////////////////////////////////
/* Constructor and Destructor */
ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy)
{
	*this = toCopy;
}

ScalarConverter::~ScalarConverter(void)
{
}

/* Operator */
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& toCopy)
{
	(void) toCopy;
	return *this;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:55:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/02 20:32:58 by clorcery         ###   ########.fr       */
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
	std::cout.precision(size);

	if (type == "f")
	{
		char *endptr;
		float f = strtof(toConvert.c_str(), &endptr);
		if ((f >= 0  && f < 32) || (f >= 127 && f < 128))
			std::cout << "char   : no displayable" << std::endl;
		else if (f > 127 || f < 0)
			std::cout << "char : it's impossible" << std::endl; 
		else 
			std::cout << "char   : " << static_cast<char>(f) << std::endl;
		std::cout << "int : " << static_cast<int>(f) << std::endl;
	
		std::cout << "float  : " << f << "f" << std::endl;
		std::cout << "double  : " << static_cast<double>(f) << std::endl;
	}
	if (type == "d")
	{
		char *endptr;
		double d = strtod(toConvert.c_str(), &endptr);
		if ((d >= 0  && d < 32) || (d >= 127 && d < 128))
			std::cout << "char   : no displayable" << std::endl;
		else if (d > 127 || d < 0)
			std::cout << "char : it's impossible" << std::endl; 
		else 
			std::cout << "char   : " << static_cast<char>(d) << std::endl;
		std::cout << "int : " << static_cast<int>(d) << std::endl;
		std::cout << "float  : " <<  static_cast<float>(d)<< "f" << std::endl;
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
		if ((i >= 0  && i < 32) || i == 127)
			std::cout << "char   : no displayable" << std::endl;
		else if (i > 127 || i < 0)
			std::cout << "char : it's impossible" << std::endl; 
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
	//gerer les overflow de float et double -- ok a reorganiser !!
	char *endptr;
	double num = strtod(strToConvert.c_str(), &endptr);
	if (errno == ERANGE)
		return false;
	if (type == "i" && num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min())
		return true;
	if (type == "f")
	{
		std::cout << "ok" << std::endl;
		char *endptrs;
		float numFloat = strtof(strToConvert.c_str(), &endptrs);
		if (errno == ERANGE) 
		{
			std::cout << "lol" << std::endl;
			return false;
		}
		if (numFloat <= std::numeric_limits<float>::max() && numFloat >= std::numeric_limits<float>::min())
		return true;
	}
	if (type == "d" && num <= std::numeric_limits<double>::max() && num >= std::numeric_limits<double>::min())
		return true;
	return false;
}

std::string checkParsing(std::string strToConvert)
{
	if (strToConvert == "")
		return "";
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
			return "";
		}
	}
	char lastChar = strToConvert[strToConvert.size() - 1];
	if (lastChar == 'f')
	{
		//verifier les cas suivants : 42..f | .42.2f | .42f | 42.f | 42.af | a42.2f

		if (checkOverflow(strToConvert, "f") == true)
			return "f";
	}
	// if (checkOverflow(strToConvert, "d") == true)
	// 	return "d";
	return "";
}

void ScalarConverter::convert(std::string toConvert)
{
	std::string pseudoLiterals = checkPseudoLiterals(toConvert);
	if (pseudoLiterals == "f" || pseudoLiterals == "d")
		convertPseudoLitterals(toConvert, pseudoLiterals);
	else
	{
		std::string type = checkParsing(toConvert);
		if (type != "")
			convertLiterals(toConvert, type);
		else
			std::cout << "Bad argument" << std::endl;
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


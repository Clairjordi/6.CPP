/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:55:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/01 20:44:31 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Member Function */

std::string checkPseudoLiterals(std::string literals)
{
	std::string tabLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	//compare literals avec tabLiterals
	//retourne f ou d 
	//sinon NULL

}


void ScalarConverter::convert(std::string toConvert)
{
	std::string pseudoLiterals = checkPseudoLiterals(toConvert);
	if (pseudoLiterals = "f" || pseudoLiterals = "d")
		convertPseudoLitterals(toConvert, pseudoLiterals);
	else
		std::cout << "in progress" << std::endl;
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


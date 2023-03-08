/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:55:39 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/08 16:35:00 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cerrno>

class ScalarConverter
{
	public:

		static void convert(std::string toConvert);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& toCopy);
		ScalarConverter& operator=(const ScalarConverter& toCopy);

		~ScalarConverter();
};

#endif

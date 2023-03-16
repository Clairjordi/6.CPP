/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:23:19 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/16 11:19:23 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cout << "Please, put a one file as argument" << std::endl;
		return 1;
	}
	//std::ifstream file(argv[1]);
	std::ifstream dataFile("data.csv");
	if (/*!file.is_open() ||*/ !dataFile.is_open())
	{
		std::cout << "Open infile failed" << std::endl;
		return 1;
	}
	BitcoinExchange data;
	data.recupData(dataFile);
	//file.close()
	dataFile.close();
	return 0;
}

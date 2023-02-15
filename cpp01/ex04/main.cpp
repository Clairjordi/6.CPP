/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:54:15 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/12 18:56:40 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string replaceValue(std::string line, std::string s1, std::string s2)
{
	std::string tmp;
	std::string::size_type i = 0;
	std::string::size_type index = 0;

	for (int j = 0; line[j]; j++)
	{
		index = line.find(s1, index);
		if (std::string::npos == index)
		{
			tmp += line.substr(i);
			break ;
		}
		if (std::string::npos != index)
		{
			tmp += line.substr(i, (index - i));
			tmp += s2;
			index += s1.size();	
			i = index;
		}
		if (line[i] == '\0')
			break ;
	}
	return (tmp);
}


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Please enter 3 arguments" << std::endl;
		return (1);
	}

	std::ifstream ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cerr << "Open infile failed" << std::endl;
		return (1);
	}

	std::string file = argv[1];
	std::ofstream ofs((file +".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Open outfile failed " << std::endl;
		return (1);
	}

	std::string line;
	while (getline(ifs, line))
	{
		if (line.find(argv[2]) != std::string::npos) 
			line = replaceValue(line, argv[2], argv[3]);
		ofs << line << std::endl;
	} 
	ifs.close();
	ofs.close();
	return (0);
}

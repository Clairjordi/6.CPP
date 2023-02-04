/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:54:15 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 18:45:39 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>




int main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	std::string line;
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Open infile failed" << std::endl;
		return (1);
	}
	std::string file = argv[1];
	std::ofstream ofs((file + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cout << "Open outfile failed " << std::endl;
		return (1);
	}
	while (getline(ifs, line))
	{
		if (line.compare(argv[2]) == 0)
			ofs << argv[3];
		ofs << line;
		ofs << std::endl;
	} 




	ifs.close();
	ofs.close();
	return (0);

}

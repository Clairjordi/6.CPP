/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:11:01 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/06 18:01:00 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc  != 2)
	{
		std::cerr << "Please enter 1 argument" << std::endl;
		return (1);
	}

	Harl Harl;
	Harl.complain(argv[1]);
	return (0);
}

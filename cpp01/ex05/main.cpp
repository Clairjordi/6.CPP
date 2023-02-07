/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:11:01 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/06 16:48:44 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl Harl;

	std::cout << "[DEBUG] : ";
	Harl.complain("DEBUG");
	
	std::cout << "[INFO] : ";
	Harl.complain("INFO");
	
	std::cout << "[WARNING] : ";
	Harl.complain("WARNING");
	
	std::cout << "[ERROR] : ";
	Harl.complain("ERROR");

	std::cout << "[OTHER] : ";
	Harl.complain("LOL");
	
	return (0);
}

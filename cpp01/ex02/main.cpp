/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:56:46 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/04 14:06:43 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "address of the string in memory : " << &string << std::endl;
	std::cout << "address of the stringPTR in memory : " << stringPTR << std::endl;
	std::cout << "address of the stringREF in memory : " << &stringREF << std::endl;

	std::cout << "value of the string : " << string << std::endl;
	std::cout << "value of the stringPTR : " << *stringPTR << std::endl;
	std::cout << "value of the stringREF : " << stringREF << std::endl;

	return (0);
}

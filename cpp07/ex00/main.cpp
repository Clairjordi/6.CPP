/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/09 18:54:23 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
	{
		int a = 2;
		int b = 10;
		std::cout << "Value a = " << a << " && value b = " << b << std::endl;
		::swap(a, b);

		std::cout << "swap : a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Value c = " << c << " && value d = " << d << std::endl;
		
		::swap(c, d);
		std::cout << "swap : c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	std::cout << std::endl;
	{
		float e = 3.14f;
		float f = 3.14f;
		std::cout << "Value e = " << e << " && value f = " << f << std::endl;
		
		::swap(e, f);
		std::cout << "swap : e = " << e << ", f = " << f << std::endl;
		std::cout << "min(c, d) = " << ::min(e, f) << std::endl;
		std::cout << "max(c, d) = " << ::max(e, f) << std::endl;

	}
	return 0;
}

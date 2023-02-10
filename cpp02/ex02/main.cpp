/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:21:01 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/09 17:22:42 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed 		a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );
    
	std::cout<< a << std::endl;
	std::cout<< ++a << std::endl;
	std::cout<< a << std::endl;
	std::cout<< a++ << std::endl;
	std::cout<< a << std::endl;
    
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;
	
	//additional tests
	Fixed c(42);
	Fixed d(2);
	Fixed e(1.5f);

	std::cout << "subtraction : c - e = " << c - e << std::endl;
	std::cout << "multiplication : c * e = " << c * e << std::endl;
	std::cout << "division : c / d = " << c / d << std::endl;
	std::cout << "comparaison d == e is ";
	if (d == e)
		std::cout << "true" << std::endl;
	else 
		std::cout << "false" << std::endl;

	std::cout << "min between c, e : "<< Fixed::min(c, e) << std::endl;
	
	return 0;
}


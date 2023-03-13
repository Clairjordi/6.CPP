/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/13 17:36:45 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "~~~Test with add Number : ~~~" << std::endl;
	{
		try{
			Span sp(6);

			sp.addNumber(8);
			sp.addNumber(10);
			sp.addNumber(90);
			sp.addNumber(5);
			sp.addNumber(18);
			sp.addNumber(9);
			std::cout << sp << std::endl;
			std::cout << "Function shortest called : " << sp.shortestSpan() << std::endl;
			std::cout << "Function longtest called : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e){
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~Test with add Multiple Number : ~~~" << std::endl;
	{
		try{
			Span sp(5);

			int array[] = {2147483647, 30, 2, -2147483648, 20};
			sp.addMultNumber(5, array);
			std::cout << sp << std::endl;
			std::cout << "Function shortest called : " << sp.shortestSpan() << std::endl;
			std::cout << "Function longtest called : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e){
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~Test with an error -span is full- : ~~~" << std::endl;
	{
		try{
			Span sp(2);

			int array[] = {2647, 8, 2, -2, 20};
			sp.addMultNumber(5, array);
			std::cout << sp << std::endl;
			std::cout << "Function shortest called : " << sp.shortestSpan() << std::endl;
			std::cout << "Function longtest called : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e){
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~Test with an error -Distance calculation impossible- : ~~~" << std::endl;
	{
		try{
			Span sp(1);

			sp.addNumber(8);
			std::cout << sp << std::endl;
			std::cout << "Function shortest called : " << sp.shortestSpan() << std::endl;
			std::cout << "Function longtest called : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e){
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "~~~Test with add Multiple Number by copy : ~~~" << std::endl;
	{
		try{
			Span spToCopy(10);
			Span sp(spToCopy);

			int array[] = {27, 8, 2, -2, 20, -9, 66, 456, 30, 44};
			sp.addMultNumber(10, array);
			std::cout << sp << std::endl;
			std::cout << "Function shortest called : " << sp.shortestSpan() << std::endl;
			std::cout << "Function longtest called : " << sp.longestSpan() << std::endl;
		}
		catch (std::exception & e){
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}

	// std::cout << std::endl;
	// std::cout << "~~~Test with an array of 11000 : ~~~" << std::endl;
	// {
	// 	try{
	// 		Span sp(11000);
    //
	// 		int array[11000];
	// 		for (int i = 0; i < 11000; i++)
	// 			array[i] = i + 1;
	// 		sp.addMultNumber(11000, array);
	// 		std::cout << sp << std::endl;
	// 		std::cout << "Function shortest called : " << sp.shortestSpan() << std::endl;
	// 		std::cout << "Function longtest called : " << sp.longestSpan() << std::endl;
	// 	}
	// 	catch (std::exception & e){
	// 		std::cout << "ERROR : " << e.what() << std::endl;
	// 	}
	// }
	return 0;
}

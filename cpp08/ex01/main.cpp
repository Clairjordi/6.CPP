/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:10:38 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/12 19:28:30 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		try{
			Span sp(6);

			sp.addNumber(8);
			sp.addNumber(3);
			int array[] = {1, 2, 3, 4};
			sp.addMultNumber(5, array);
			std::cout << sp << std::endl;
			int *parray = 0;

			sp.addMultNumber(5, parray);
			std::cout << sp << std::endl;
		}
		catch (std::exception & e){
			std::cout << "ERROR : " << e.what() << std::endl;
		}
	}
	//std::cout << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:00:14 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/01 17:52:23 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *dataPtr;
	Data data;
	uintptr_t unsInt;

	// init
	data.nb = 3;
	dataPtr = &data;
	std::cout << "data adress : " << dataPtr << " : nb = " << data.nb << std::endl;

	// get adress -> uintptr
	unsInt = Serializer::serialize(dataPtr);
	std::cout << "unsInt adress (through by serialize function) : " << unsInt << " -> nb = " << data.nb << " / convert in hexa = "<< std::hex << unsInt <<std::endl;

	// print adress -> deserialize( unsint )
	std::cout << "data adress (through by deserialize function) : " << Serializer::deserialize(unsInt) << " -> nb = " << data.nb << std::endl;
	return 0;
}

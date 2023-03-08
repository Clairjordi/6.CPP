/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:00:14 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/08 15:40:42 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *dataPtr;
	Data data;
	uintptr_t serializeValue = 0;

	// init
	data.nb = 3;
	dataPtr = &data;
	std::cout << "Adress of data : " << &data << std::endl;

	// get adress -> uintptr
	std::cout << "Adress of serializeValue : " << serializeValue << std::endl;
	serializeValue = Serializer::serialize(dataPtr);
	std::cout << "serializeValue adress (through by serialize function) : " << serializeValue << " / convert in hexa = " << std::hex << serializeValue << std::endl;

	// print adress -> deserialize( unsint )
	std::cout << "data adress (through by deserialize function) : " << Serializer::deserialize(serializeValue) << std::endl;
	return 0;
}

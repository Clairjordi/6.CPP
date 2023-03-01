/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:50:16 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/01 17:09:20 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* Constructor and Destructor */
Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer& toCopy)
{
	*this = toCopy;
}

Serializer::~Serializer(void)
{
}

/* Member Function */
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));	
}

/* Operator */
Serializer& Serializer::operator=(const Serializer& toCopy)
{
	(void) toCopy;
	return *this;
}


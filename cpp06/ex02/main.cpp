/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:06:27 by clorcery          #+#    #+#             */
/*   Updated: 2023/03/01 19:50:54 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>

int main()
{
	std::srand(time(NULL));
	Base *randPtr;
	{
	randPtr = generate();
	identify(randPtr);
	delete randPtr;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	{
	randPtr = generate();
	Base &randRef = *randPtr;
	identify(randRef);
	delete randPtr;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:18:37 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/15 20:05:30 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & toCopy);
		MateriaSource & operator=(const MateriaSource & toCopy);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);

	private:
		AMateria* _arrayMateria[4];
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:59:49 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/08 12:03:39 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& toCopy);
		Fixed & operator=(const Fixed& toCopy);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int	_fixedComma;
		static const int _bit;
};

#endif

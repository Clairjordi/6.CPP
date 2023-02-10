/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:59:49 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/08 16:33:25 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& toCopy);
		Fixed & operator=(const Fixed& toCopy);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int		toInt() const;

	private:
		int	_fixedComma;
		static const int _bit;
};

std::ostream & operator<<( std::ostream & o,  Fixed const & i);

#endif

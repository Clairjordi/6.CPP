/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:59:49 by clorcery          #+#    #+#             */
/*   Updated: 2023/02/09 16:41:34 by clorcery         ###   ########.fr       */
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
		Fixed & operator=(const Fixed & rhs);
		~Fixed();

	
		bool	operator>(const Fixed & rhs) const;
		bool	operator<(const Fixed & rhs) const;
		bool	operator>=(const Fixed & rhs) const;
		bool	operator<=(const Fixed & rhs) const;
		bool	operator==(const Fixed & rhs) const;
		bool	operator!=(const Fixed & rhs) const;
		Fixed	operator+(const Fixed & rhs) const;
		Fixed	operator-(const Fixed & rhs) const;
		Fixed	operator*(const Fixed & rhs) const;
		Fixed	operator/(const Fixed & rhs) const;
		Fixed & operator++();
		Fixed	operator++(int i);
		Fixed & operator--();
		Fixed	operator--(int i);


		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		static Fixed min(Fixed & ref1,Fixed & ref2);
		static Fixed max(Fixed & ref1, Fixed & ref2);
		static Fixed min(const Fixed & ref1, const Fixed & ref2);
		static Fixed max(const Fixed & ref1, const Fixed & ref2);

	private:
		int	_fixedComma;
		static const int _bit;
};

std::ostream & operator<<( std::ostream & o,  Fixed const & i);

#endif

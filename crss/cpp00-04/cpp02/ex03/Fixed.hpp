/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:35:23 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 14:51:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					m_fixed_val;
		static const int	m_fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed& operator=(const Fixed &src);
		bool operator>(const Fixed &src) const;
		bool operator<(const Fixed &src) const;
		bool operator>=(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);	
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed& min(Fixed& first, Fixed& second); 
		static const Fixed& min(const Fixed& first, const Fixed& second); 
		static Fixed& max(Fixed& first, Fixed& second); 
		static const Fixed& max(const Fixed& first, const Fixed& second); 
};

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed);
#endif

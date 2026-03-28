/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:35:23 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 20:47:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	m_fixed_val;
		static const int	m_fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed& operator=(const Fixed &src);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);	
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed);
#endif

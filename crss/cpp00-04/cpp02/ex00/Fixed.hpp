/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:35:23 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 20:46:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
	private:
		int				 m_fixed_val;
		static const int m_fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);

		Fixed& operator=(const Fixed &src);

		int 	getRawBits(void) const;
		void	setRawBits(int const raw);	
};
#endif

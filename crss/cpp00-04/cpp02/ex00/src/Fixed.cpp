/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/14 12:27:20 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	this->m_fixed_val = 0;
}

Fixed::Fixed(const Fixed &src) {
	this->m_fixed_val = src.m_fixed_val;
}

Fixed& Fixed::operator=(const Fixed &src) {
	this->m_fixed_val = src.m_fixed_val;
	return *this;
}

Fixed::~Fixed(void) {
}

int		Fixed::getRawBits(void) const{
	return (this->m_fixed_val);
}

void	Fixed::setRawBits(int const raw) {
	this->m_fixed_val = raw;
}

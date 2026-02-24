/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/14 14:26:28 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cerr << "Default constructor called." << std::endl;
	this->m_fractional_bits = 8;
	this->m_fixed_val = 0;
}

Fixed::Fixed(const int value) {
	std::cerr << "Int constructor called." << std::endl;
	this->m_fractional_bits = 8;
	this->m_fixed_val = value << this->m_fractional_bits;
}

Fixed::Fixed(const float value) {
	std::cerr << "Float constructor called." << std::endl;
	this->m_fractional_bits = 8;
	this->m_fixed_val = roundf(value * (1 << this->m_fractional_bits));
}

Fixed::Fixed(const Fixed &src) {
	std::cerr << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cerr << "Copy assignment constructor called." << std::endl;
	this->m_fractional_bits = 8;
	this->m_fixed_val = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cerr << "Destructor called." << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (this->m_fixed_val);
}

void	Fixed::setRawBits(int const raw) {
	this->m_fixed_val = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->m_fixed_val / (1 << this->m_fractional_bits));
}

int		Fixed::toInt(void) const {
	return (this->m_fixed_val >> this->m_fractional_bits);
}

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed){
	return os << fixed.toFloat();
}

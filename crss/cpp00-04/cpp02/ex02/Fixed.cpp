/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 23:05:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : m_fixed_val(0) {
	//std::cerr << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int value) : m_fixed_val(value << m_fractional_bits) {
	//std::cerr << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float value) : m_fixed_val(roundf(value * (1 << m_fractional_bits))) {
	//std::cerr << "Float constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	//std::cerr << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	//std::cerr << "Destructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src) {
	//std::cerr << "Copy assignment operator called." << std::endl;
	if (this != &src)
		m_fixed_val = src.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &src) const {
	return (m_fixed_val > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const {
	return (m_fixed_val < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const {
	return (m_fixed_val >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const {
	return (m_fixed_val <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const {
	return (m_fixed_val == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const {
	return (m_fixed_val != src.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(m_fixed_val + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(m_fixed_val - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits((m_fixed_val * fixed.getRawBits()) >> m_fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits((m_fixed_val << m_fractional_bits) / fixed.getRawBits());
	return result;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	m_fixed_val += 1;
	return old;
}

Fixed& Fixed::operator++() {
	m_fixed_val += 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	m_fixed_val -= 1;
	return old;
}

Fixed& Fixed::operator--() {
	m_fixed_val -= 1;
	return *this;
}

int		Fixed::getRawBits(void) const {
	return (m_fixed_val);
}

void	Fixed::setRawBits(int const raw) {
	m_fixed_val = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)m_fixed_val / (1 << m_fractional_bits));
}

int		Fixed::toInt(void) const {
	return (m_fixed_val >> m_fractional_bits);
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
	if (first < second)
		return first;
	return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
	if (first < second)
		return first;
	return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
	if (first > second)
		return first;
	return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
	if (first > second)
		return first;
	return second;
}

std::ostream& 	operator<<(std::ostream& os, const Fixed& fixed){
	return os << fixed.toFloat();
}

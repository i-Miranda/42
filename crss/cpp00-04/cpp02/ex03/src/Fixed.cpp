/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/14 19:27:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cerr << "Default constructor called." << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int value) {
	std::cerr << "Int constructor called." << std::endl;
	this->setRawBits(value << m_fractional_bits);
}

Fixed::Fixed(const float value) {
	std::cerr << "Float constructor called." << std::endl;
	this->setRawBits(roundf(value * (1 << m_fractional_bits)));
}

Fixed::Fixed(const Fixed &src) {
	std::cerr << "Copy constructor called." << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cerr << "Destructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cerr << "Copy assignment constructor called." << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

bool Fixed::operator>(const Fixed &src) const {
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const {
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const {
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const {
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const {
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const {
	return (this->getRawBits() != src.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits((this->getRawBits() * fixed.getRawBits()) >> m_fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits((this->getRawBits() << m_fractional_bits) / fixed.getRawBits());
	return result;
}

Fixed Fixed::operator++(int) {
	Fixed old(*this);
	this->setRawBits(this->getRawBits() + 1);
	return old;
}

Fixed Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed old(*this);
	this->setRawBits(this->getRawBits() - 1);
	return old;
}

Fixed Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

int		Fixed::getRawBits(void) const {
	return (this->m_fixed_val);
}

void	Fixed::setRawBits(int const raw) {
	this->m_fixed_val = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (1 << m_fractional_bits));
}

int		Fixed::toInt(void) const {
	return (this->getRawBits() >> m_fractional_bits);
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

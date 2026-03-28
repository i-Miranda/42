/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 02:44:26 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) { 
	std::cout << "Default constructor called" << std::endl;
	m_fixed_val = 0;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	m_fixed_val = src.m_fixed_val;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (m_fixed_val);
}

void Fixed::setRawBits(int const raw) {
	m_fixed_val = raw;
}

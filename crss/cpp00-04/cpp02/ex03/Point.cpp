/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:33:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 20:36:06 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point(void) : m_x(0.0f), m_y(0.0f) {
	std::cerr << "Default constructor called." << std::endl;
}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {
	std::cerr << "Float constructor called." << std::endl;
}

Point::Point(const Point &src) : m_x(src.m_x), m_y(src.m_y) {
	std::cerr << "Copy constructor called." << std::endl;
}

Point::~Point(void) {
	std::cerr << "Destructor called." << std::endl;
}

Point& Point::operator=(const Point &src) {
	std::cerr << "Copy assignment operator called." << std::endl;
	(void)src;
	return *this;
}

Point Point::operator-(const Point &point) const {
	return (Point((m_x - point.get_x()).toFloat(),
				(m_y - point.get_y()).toFloat()));
}

Point Point::operator+(const Point &point) const {
	return (Point((m_x + point.get_x()).toFloat(),
			(m_y + point.get_y()).toFloat()));
}

Fixed Point::operator*(const Point &point) const {
	Fixed scalar;
	scalar = Fixed(m_x * point.get_x() + m_y * point.get_y());
	return scalar;
}

float	Point::get_x(void) const {
	return m_x.toFloat();
}

float	Point::get_y(void) const {
	return m_y.toFloat();
}

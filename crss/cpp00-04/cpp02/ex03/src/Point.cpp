/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:33:02 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 01:46:04 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point(void) {
	std::cerr << "Default constructor called." << std::endl;
	this->set_x(0.0f);
	this->set_y(0.0f);
}

Point::Point(const float x, const float y) {
	std::cerr << "Float constructor called." << std::endl;
	this->set_x(x);
	this->set_y(y);
}

Point::Point(const Point &src) {
	std::cerr << "Copy constructor called." << std::endl;
	*this = src;
}

Point::~Point(void) {
	std::cerr << "Destructor called." << std::endl;
}

Point& Point::operator=(const Point &src) {
	std::cerr << "Copy assignment constructor called." << std::endl;
	this->set_x(src.get_x());
	this->set_y(src.get_y());
	return *this;
}

Point Point::operator-(const Point &point) const {
	Point difference;
	difference = Point(this->get_x() - point.get_x(), this->get_y() - point.get_y());
	return difference;
}

Point Point::operator+(const Point &point) const {
	Point sum;
	sum = Point(this->get_x() + point.get_x(), this->get_y() + point.get_y());
	return sum;
}

Fixed Point::operator*(const Point &point) const {
	Fixed scalar;
	scalar = Fixed(this->get_x() * point.get_x() + this->get_y() * point.get_y());
	return scalar;
}

float	Point::get_x(void) const {
	return m_x.toFloat();
}

float	Point::get_y(void) const {
	return m_y.toFloat();
}

void	Point::set_x(const float x) {
	m_x = Fixed(x);
}

void	Point::set_y(const float y) {
	m_y = Fixed(y);
}

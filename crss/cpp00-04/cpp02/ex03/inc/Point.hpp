/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:33:22 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/17 16:58:46 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class Point {
	private:
		float m_x;
		float m_y;

	public:
		Point(void);
		Point(const float x, const float y);	
		Point(const Point &src);
		~Point(void);

		Point& operator=(const Point &src);	
		
		Point operator-(const Point &point) const;
		Point operator+(const Point &point) const;
		Fixed operator*(const Point &point) const;

		float 	get_x(void) const;
		float 	get_y(void) const;
		void	set_x(const float x);
		void	set_y(const float y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:50:28 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/17 17:03:30 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed e_1;
	Fixed e_2;
	Fixed e_3;
	Fixed zero;
	
	zero = Fixed(0);
	e_1 = (b - a) * (point - a);
	e_2 = (c - b) * (point - b);
	e_3 = (a - c) * (point - c);

	return ((e_1 <= zero && e_2 <= zero && e_3 <= zero)
			|| (e_1 >= zero && e_2 >= zero && e_3 >= zero));
}

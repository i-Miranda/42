/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/17 17:17:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>

static void print_point_prefix(const Point &point, std::string name) {
	std::cout << "Point " << name << " (" << point.get_x() << ", " << point.get_y() << ") ";
}

int	main(int argc, char *argv[]) {
	Point a;
	Point b;
	Point c;
	Point point;
	bool	point_inside;

	if (argc != 9)
		return (1);
	a = Point(std::atof(argv[1]), std::atof(argv[2]));
	print_point_prefix(a, "a");
	std::cout << " initialized." << std::endl;
	b = Point(std::atof(argv[3]), std::atof(argv[4]));
	print_point_prefix(b, "b");
	std::cout << " initialized." << std::endl;
	c = Point(std::atof(argv[5]), std::atof(argv[6]));
	print_point_prefix(c, "c");
	std::cout << " initialized." << std::endl;
	point = Point(std::atof(argv[7]), std::atof(argv[8]));
	print_point_prefix(point, "point");
	std::cout << " initialized." << std::endl;
	point_inside = bsp(a, b, c, point);
	print_point_prefix(point, "point");
	if (point_inside)
		std::cout << " is inside the triangle." << std::endl;
	else
		std::cout << " is not inside the triangle." << std::endl;
	return (0);
}

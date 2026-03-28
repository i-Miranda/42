/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 20:33:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>

static void print_point_prefix(const Point &point, std::string name) {
	std::cout << "Point " << name << " (" << point.get_x() << ", " << point.get_y() << ") ";
}

int	main(int argc, char *argv[]) {
	if (argc != 9) {
		std::cout << "ERROR: Must be 9 args." << std::endl;
		std::cout << "Usage: " << std::endl;
		return (1);
	}
	
	float ax = std::atof(argv[1]);
	float ay = std::atof(argv[2]);
	float bx = std::atof(argv[3]);
	float by = std::atof(argv[4]);
	float cx = std::atof(argv[5]);
	float cy = std::atof(argv[6]);
	float px = std::atof(argv[7]);
	float py = std::atof(argv[8]);

	Point a(ax, ay);
	Point b(bx, by);
	Point c(cx, cy);
	Point point(px, py);

	print_point_prefix(a, "a");
	std::cout << " initialized." << std::endl;
	print_point_prefix(b, "b");
	std::cout << " initialized." << std::endl;
	c = Point(std::atof(argv[5]), std::atof(argv[6]));
	std::cout << " initialized." << std::endl;
	print_point_prefix(point, "point");
	std::cout << " initialized." << std::endl;

	bool point_inside = bsp(a, b, c, point);

	print_point_prefix(point, "point");
	if (point_inside)
		std::cout << " is inside the triangle." << std::endl;
	else
		std::cout << " is not inside the triangle." << std::endl;
	return (0);
}

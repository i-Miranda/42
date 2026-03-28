/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 23:20:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
//------------SUBJECT
	{
		std::cout << "SUBJECT MAIN TEST" << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;
		
		std::cout << Fixed::max(a, b) << std::endl;
	}
//------------END OF SUBJECT MAIN
	std::cout << std::endl;
//------------CONSTRUCTORS AND ASSIGNMENT TEST
	{
		std::cout << "CONSTRUCTORS TEST" << std::endl;
		Fixed a;
		Fixed b(42);
		Fixed c(42.42f);
		Fixed d(b);
	
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		
		std::cout << std::endl;

		std::cout << "ASSIGNMENT TEST" << std::endl;
		a = c;	
		std::cout << "Now a should equal c." << std::endl;
		std::cout << "a = " << a << std::endl;
	}
//------------END OF CONSTRUCTORS AND ASSIGNMENT TEST
	std::cout << std::endl;
//------------OPERATORS TESTS
	{
		std::cout << "OPERATORS TESTS" << std::endl;
		Fixed x(5.5f);
		Fixed y(2.25f);
		Fixed z(2.25f);

		std::cout << std::endl;

		std::cout << "COMPARISONS TESTS" << std::endl;
		std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
		std::cout << "x > y : " << (x > y) << std::endl;
		std::cout << "x < y : " << (x < y) << std::endl;
		std::cout << "x >= z : " << (x >= y) << std::endl;
		std::cout << "x <= z : " << (x <= y) << std::endl;
		std::cout << "x == z : " << (x == z) << std::endl;
		std::cout << "x != y : " << (x != y) << std::endl;
		
		std::cout << std::endl;

		std::cout << "ARITHMETIC TESTS" << std::endl;
		std::cout << "x + y = " << (x + y) << std::endl;
		std::cout << "x - y = " << (x - y) << std::endl;
		std::cout << "x * y = " << (x * y) << std::endl;
		std::cout << "x / y = " << (x / y) << std::endl;

		std::cout << std::endl;

		std::cout << "INCREMENT/DECREMENT TESTS" << std::endl;
		Fixed inc;
	
		std::cout << "inc    = " << inc << std::endl;
		std::cout << "++inc  = " << ++inc << std::endl;
		std::cout << "inc    = " << inc << std::endl;
		std::cout << "inc++  = " << inc++ << std::endl;
		std::cout << "inc    = " << inc << std::endl;
		std::cout << "--inc  = " << --inc << std::endl;
		std::cout << "inc    = " << inc << std::endl;
		std::cout << "inc--  = " << inc-- << std::endl;
		std::cout << "inc    = " << inc << std::endl;
	}
//------------END OF OPERATORS TESTS
	std::cout << std::endl;
//------------MIN and MAX TESTS
	{
		std::cout << "MIN and MAX TESTS" << std::endl;
		Fixed min_1(3.5f);
		Fixed max_1(7.25f);
		const Fixed min_2(1.125f);
		const Fixed max_2(1.5f);
		std::cout << "min_1 = " << min_1 << std::endl;
		std::cout << "max_1 = " << max_1 << std::endl;
		std::cout << "min_2 = " << min_2 << std::endl;
		std::cout << "max_2 = " << max_2 << std::endl;
		
		std::cout << std::endl;

		std::cout << "min(min_1, max_1) = " << Fixed::min(min_1, max_1) << std::endl;
		std::cout << "max(min_1, max_1) = " << Fixed::max(min_1, max_1) << std::endl;

		std::cout << std::endl;

		std::cout << "CONST MIN and MAX TESTS" << std::endl;
		std::cout << "min(min_2, max_2) = " << Fixed::min(min_2, max_2) << std::endl;
		std::cout << "max(min_2, max_2) = " << Fixed::max(min_2, max_2) << std::endl;
	}
//------------MIN and MAX TESTS
	std::cout << std::endl;
//------------CONVERSION TESTS
	{
		std::cout << "CONVERSION TESTS" << std::endl;
		
		Fixed convert(12.12f);

		std::cout << "convert           = " << convert << std::endl;
		std::cout << "convert.toInt()   = " << convert.toInt() << std::endl;
		std::cout << "convert           = " << convert << std::endl;
		std::cout << "convert.toFloat() = " << convert.toFloat() << std::endl;
		std::cout << "convert           = " << convert << std::endl;
		std::cout << "convert.toInt()   = " << convert.toInt() << std::endl;
	}
	return (0);
}

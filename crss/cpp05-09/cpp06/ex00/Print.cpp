/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:09:33 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/20 17:32:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"
#include "CheckLiteral.hpp"
#include <iomanip>
#include <iostream>

void printChar(t_conversions *conversions) {
  std::cout << "char: ";
  if (conversions == NULL)
    std::cout << "impossible" << std::endl;
  else if (!std::isprint(static_cast<unsigned char>(conversions->char_type)))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << "'" << conversions->char_type << "'" << std::endl;
}

void printInt(t_conversions *conversions) {
  std::cout << "int: ";
  if (conversions == NULL)
    std::cout << "impossible" << std::endl;
  else
    std::cout << conversions->int_type << std::endl;
}

void printFloat(t_conversions *conversions) {
  std::cout << "float: ";
  if (conversions == NULL)
    std::cout << "impossible" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << conversions->float_type
              << "f" << std::endl;
}

void printDouble(t_conversions *conversions) {
  std::cout << "double: " << std::endl;
  if (conversions == NULL)
    std::cout << "impossible" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1) << conversions->double_type
              << std::endl;
}

void printImpossible(void) {
  printChar(NULL);
  printInt(NULL);
  printFloat(NULL);
  printDouble(NULL);
}

void printPseudoLiteral(std::string const &pseudo_literal) {
  std::string double_literal = pseudo_literal;

  if (isFloatPseudoLiteral(pseudo_literal)) {
    double_literal.erase(double_literal.length() - 1);
  }
  printChar(NULL);
  printInt(NULL);
  std::cout << "float: " << double_literal << "f" << std::endl;
  std::cout << "double: " << double_literal << std::endl;
}

void printConversions(t_conversions const &conversions) {
  t_conversions ptr = static_cast<t_conversions>(conversions);
  printChar(&ptr);
  printInt(&ptr);
  printFloat(&ptr);
  printDouble(&ptr);
}

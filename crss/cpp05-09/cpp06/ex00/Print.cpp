/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:09:33 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/08 10:09:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Print.hpp"
#include "PseudoLiteral.hpp"
#include <iostream>

static void printChar(t_conversions *conversions) {
  if (conversions == NULL)
    std::cout << "char: impossible" << std::endl;
  else
    std::cout << "char: " << conversions->char_type << std::endl;
}

static void printInt(t_conversions *conversions) {
  if (conversions == NULL)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << conversions->int_type << std::endl;
}

static void printFloat(t_conversions *conversions) {
  if (conversions == NULL)
    std::cout << "float: impossible" << std::endl;
  else
    std::cout << "float: " << conversions->float_type << std::endl;
}

static void printDouble(t_conversions *conversions) {
  if (conversions == NULL)
    std::cout << "double: impossible" << std::endl;
  else
    std::cout << "double: " << conversions->double_type << std::endl;
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

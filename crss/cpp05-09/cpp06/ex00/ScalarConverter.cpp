/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:25:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/22 16:58:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "CheckLiteral.hpp"
#include "Conversions.hpp"
#include "Print.hpp"
#include <cfloat>
#include <climits>
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
  if (this != &src)
    (void)src;
  return *this;
}

void ScalarConverter::convert(std::string const &literal) {
  if (isPseudoLiteral(literal)) {
    printPseudoLiteral(literal);
    return;
  }

  t_conversions conversions;

  if (isCharLiteral(literal)) {
    if (literal.length() == 3)
      conversions.double_type = static_cast<unsigned char>(literal[1]);
    else
      conversions.double_type = static_cast<unsigned char>(literal[0]);
  } else {
    std::string value = literal;
    if (hasFloatSuffix(value)) {
      value.erase(value.length() - 1);
      if (value.empty()) {
        printImpossible();
        return;
      }
    }
    if (!isDecimalLiteral(value)) {
      printImpossible();
      return;
    }
    std::stringstream ss(value);
    ss >> conversions.double_type;
    if (ss.fail() || !ss.eof()) {
      printImpossible();
      return;
    }
  }

  conversions.float_type = 0;
  conversions.int_type = 0;
  conversions.char_type = 0;

  bool float_overflow =
      (conversions.double_type > static_cast<double>(FLT_MAX) ||
       conversions.double_type < -static_cast<double>(FLT_MAX));
  if (!float_overflow)
    conversions.float_type = static_cast<float>(conversions.double_type);

  bool int_overflow =
      (conversions.double_type < static_cast<double>(INT_MIN) ||
       conversions.double_type > static_cast<double>(INT_MAX) + 1.0);
  if (!int_overflow)
    conversions.int_type = static_cast<int>(conversions.double_type);

  bool char_overflow =
      (conversions.double_type < 0.0 || conversions.double_type >= 128.0);
  if (!char_overflow)
    conversions.char_type = static_cast<char>(conversions.double_type);

  printChar(char_overflow ? NULL : &conversions);
  printInt(int_overflow ? NULL : &conversions);
  printFloat(float_overflow ? NULL : &conversions);
  printDouble(&conversions);
}

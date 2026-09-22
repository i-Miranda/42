/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:25:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/22 19:23:28 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "CheckLiteral.hpp"
#include "Conversions.hpp"
#include "Print.hpp"

#include <cfloat>
#include <climits>
#include <cstddef>
#include <sstream>
#include <string>

static bool parseChar(std::string const &literal, char &result) {
  if (literal.length() == 3)
    result = literal[1];
  else
    result = literal[0];

  return true;
}

static bool parseLong(std::string const &text, long &result) {
  std::stringstream stream(text);

  stream >> result;
  return !stream.fail() && stream.eof();
}

static bool parseDouble(std::string const &text, double &result) {
  std::stringstream stream(text);

  stream >> result;
  return !stream.fail() && stream.eof();
}

static bool isFloatOutOfRange(double value) {
  return value > static_cast<double>(FLT_MAX) ||
         value < -static_cast<double>(FLT_MAX);
}

static bool isIntOutOfRange(double value) {
  return value <= static_cast<double>(INT_MIN) - 1.0 ||
         value >= static_cast<double>(INT_MAX) + 1.0;
}

static bool isCharOutOfRange(double value) {
  return value <= static_cast<double>(CHAR_MIN) - 1.0 ||
         value >= static_cast<double>(CHAR_MAX) + 1.0;
}

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

  conversions.char_type = 0;
  conversions.int_type = 0;
  conversions.float_type = 0;
  conversions.double_type = 0;

  double source_as_double = 0.0;

  if (isCharLiteral(literal)) {
    char source;
    if (!parseChar(literal, source)) {
      printImpossible();
      return;
    }
    source_as_double = static_cast<double>(source);

  } else if (isIntegerLiteral(literal)) {
    long source;

    if (!parseLong(literal, source)) {
      printImpossible();
      return;
    }

    source_as_double = static_cast<double>(source);
  } else if (isFloatLiteral(literal)) {
    std::string value = literal.substr(0, literal.length() - 1);
    double source;

    if (!parseDouble(value, source)) {
      printImpossible();
      return;
    }

    source_as_double = static_cast<double>(source);
  } else if (isDoubleLiteral(literal)) {
    double source;

    if (!parseDouble(literal, source)) {
      printImpossible();
      return;
    }

    source_as_double = source;
  } else {
    printImpossible();
    return;
  }

  conversions.double_type = source_as_double;

  const bool int_overflow = isIntOutOfRange(source_as_double);
  const bool float_overflow = isFloatOutOfRange(source_as_double);
  const bool char_overflow = isCharOutOfRange(source_as_double);

  if (!int_overflow)
    conversions.int_type = static_cast<int>(source_as_double);

  if (!float_overflow)
    conversions.float_type = static_cast<float>(source_as_double);

  if (!char_overflow)
    conversions.char_type = static_cast<char>(source_as_double);

  printChar(char_overflow ? NULL : &conversions);
  printInt(int_overflow ? NULL : &conversions);
  printFloat(float_overflow ? NULL : &conversions);
  printDouble(&conversions);
}

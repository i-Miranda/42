/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckLiteral.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:57:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/22 18:02:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CheckLiteral.hpp"

#include <cctype>

bool isFloatPseudoLiteral(std::string const &literal) {
  return literal == "nanf" || literal == "+inff" || literal == "-inff";
}

bool isPseudoLiteral(std::string const &literal) {
  return isFloatPseudoLiteral(literal) || literal == "nan" ||
         literal == "+inf" || literal == "-inf";
}

bool isDecimalLiteral(std::string const &literal) {
  if (literal.empty())
    return false;

  size_t i = 0;
  bool has_digit = false;
  bool has_dot = false;

  if (literal[i] == '+' || literal[i] == '-') {
    i++;

    if (i == literal.length())
      return false;
  }

  while (i < literal.length()) {
    if (std::isdigit(static_cast<unsigned char>(literal[i]))) {
      has_digit = true;
    } else if (literal[i] == '.') {
      if (has_dot)
        return false;

      has_dot = true;
    } else {
      break;
    }

    i++;
  }

  if (!has_digit)
    return false;

  if (i < literal.length() && (literal[i] == 'e' || literal[i] == 'E')) {
    i++;

    if (i < literal.length() && (literal[i] == '+' || literal[i] == '-')) {
      i++;
    }

    size_t exponent_start = i;

    while (i < literal.length()) {
      if (!std::isdigit(static_cast<unsigned char>(literal[i]))) {
        return false;
      }

      i++;
    }

    if (i == exponent_start)
      return false;
  }

  return i == literal.length();
}

bool isCharLiteral(std::string const &literal) {
  if (literal.length() == 1) {
    return !std::isdigit(static_cast<unsigned char>(literal[0]));
  }

  return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool hasFloatSuffix(std::string const &literal) {
  return !literal.empty() && literal[literal.length() - 1] == 'f';
}

bool hasDecimalPointOrExponent(std::string const &literal) {
  return literal.find('.') != std::string::npos ||
         literal.find('e') != std::string::npos ||
         literal.find('E') != std::string::npos;
}

bool isIntegerLiteral(std::string const &literal) {
  return isDecimalLiteral(literal) && !hasDecimalPointOrExponent(literal);
}

bool isFloatLiteral(std::string const &literal) {
  if (!hasFloatSuffix(literal))
    return false;

  std::string value = literal;
  value.erase(value.length() - 1);

  return isDecimalLiteral(value) && hasDecimalPointOrExponent(value);
}

bool isDoubleLiteral(std::string const &literal) {
  return isDecimalLiteral(literal) && hasDecimalPointOrExponent(literal);
}

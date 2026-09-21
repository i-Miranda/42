/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckLiteral.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:57:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/20 18:35:04 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckLiteral.hpp"

bool isFloatPseudoLiteral(std::string const &literal) {
  return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool isPseudoLiteral(std::string const &literal) {
  return (isFloatPseudoLiteral(literal) || literal == "nan" ||
          literal == "+inf" || literal == "-inf");
}

bool isNumericLiteral(t_conversions &c) {
  size_t i = 0;
  if (c.literal[i] == '+' || c.literal[i] == '-') {
    if (c.literal[i] == '-')
      c.is_negative = true;
    c.literal = c.literal.substr(1, c.literal.length() - 1);
    i++;
  }
}

bool isCharLiteral(t_conversions &c) {
  if (c.literal.length() == 1 &&
      !std::isdigit(static_cast<unsigned char>(c.literal[0])))
    return true;
  return c.literal.length() == 3 && c.literal[0] == '\'' &&
         c.literal[2] == '\'';
}

bool isIntLiteral(t_conversions &c) {
  if (c.literal.empty())
    return false;

  size_t i = 0;
  if (i >= c.literal.length())
    return false;
  for (; i < c.literal.length(); i++) {
    if (!std::isdigit(static_cast<unsigned char>(c.literal[i])))
      return false;
  }
  return true;
}

bool isLastCharF(t_conversions &c) {
  return (!c.literal.empty() && c.literal[c.literal.length() - 1] == 'f');
}

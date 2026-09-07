/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:25:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/07 20:31:04 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "CheckLiteral.hpp"
#include "Conversions.hpp"
#include "Print.hpp"
#include <iostream>
#include <sstream>

void ScalarConverter::convert(std::string &literal) {
  t_conversions conversions;

  if (isPseudoLiteral(literal)) {
    printPseudoLiteral(literal);
    return;
  }

  std::string numeric_literal = literal;

  if (isLastCharF(numeric_literal)) {
    numeric_literal.erase(numeric_literal.length() - 1);
  }
  std::stringstream ss(numeric_literal);
  ss >> conversions.double_type;
  if (ss.fail() || !ss.eof()) {
    printImpossible();
    return;
  }

  conversions.char_type = static_cast<char>(conversions.double_type);
  conversions.int_type = static_cast<int>(conversions.double_type);
  conversions.float_type = static_cast<float>(conversions.double_type);

  printConversions(conversions);
}

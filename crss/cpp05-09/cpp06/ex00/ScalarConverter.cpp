/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:25:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/20 18:37:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "CheckLiteral.hpp"
#include "Conversions.hpp"
#include "Print.hpp"
#include <iostream>
#include <sstream>

ScalarConverter::ScalarConverter(void) {
  std::cout << "Default ScalarConverter Constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
  std::cout << "Copy ScalarConverter Constructor called." << std::endl;
  *this = src;
}

ScalarConverter::~ScalarConverter(void) {
  std::cout << "ScalarConverter Destructor called." << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
  std::cout << "Copy assignment operator called." << std::endl;
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

  conversions.float_type = static_cast<float>(conversions.double_type);
  conversions.int_type = static_cast<int>(conversions.double_type);
  conversions.char_type = static_cast<char>(conversions.double_type);

  printConversions(conversions);
}

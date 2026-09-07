/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PseudoLiteral.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:57:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/07 22:57:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CheckLiteral.hpp"

bool isFloatPseudoLiteral(std::string const &pseudo_literal) {
  return (pseudo_literal == "nanf" || pseudo_literal == "+inff" ||
          pseudo_literal == "-inff");
}

bool isPseudoLiteral(std::string const &literal) {
  return (isFloatPseudoLiteral(literal) || literal == "nan" ||
          literal == "+inf" || literal == "-inf");
}

bool isLastCharF(std::string const &literal) {
  return (!literal.empty() && literal[literal.length() - 1] == 'f');
}

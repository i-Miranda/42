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

#include "PseudoLiteral.hpp"

bool isFloatPseudoLiteral(std::string const &pseudo_literal) {
  return (pseudo_literal == "nanf" || pseudo_literal == "+inff" ||
          pseudo_literal == "-inff");
}

bool isPseudoLiteral(std::string const &literal) {
  return (literal == "nan" || literal == "nanf" || literal == "+inff" ||
          literal == "-inff" || literal == "+inf" || literal == "-inf");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:25:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/07 20:25:51 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Conversions.hpp"
#include <iostream>

void printConversions(t_conversions const &conversions) {
  std::cout << "char: " << conversions.char_type << std::endl;
  std::cout << "int: " << conversions.int_type << std::endl;
  std::cout << "float: " << conversions.float_type << "f" << std::endl;
  std::cout << "double: " << conversions.double_type << std::endl;
}

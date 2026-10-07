/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:59:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/07 11:21:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  try {
    RPN rpn;
    int result = rpn.calculate(argv[1]);
    std::cout << result << std::endl;
  } catch (std::exception const &e) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  return 0;
}

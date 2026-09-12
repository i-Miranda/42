/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:35:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/11 10:35:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void) {
  Array<int> array_empty;
  Array<int> array_int(5);

  array_int[0] = 10;
  array_int[1] = 11;
  array_int[2] = 12;
  array_int[3] = 13;
  array_int[4] = 14;

  std::cout << array_int[0] << std::endl;
  std::cout << array_int[1] << std::endl;
  std::cout << array_int[2] << std::endl;
  std::cout << array_int[3] << std::endl;
  std::cout << array_int[4] << std::endl;

  return 0;
}

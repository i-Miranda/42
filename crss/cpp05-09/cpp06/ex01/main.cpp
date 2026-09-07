/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:53:37 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/07 11:53:38 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <climits>
#include <iostream>

int main(void) {
  Data data;
  data.value_long = LONG_MAX;
  data.value_int = 42;
  data.value_char = 'L';

  uintptr_t raw = Serializer::serialize(&data);
  Data *result = Serializer::deserialize(raw);

  std::cout << "Original Data: " << &data << std::endl;
  std::cout << "Original Data value_long: " << data.value_long << std::endl;
  std::cout << "Original Data value_int: " << data.value_int << std::endl;
  std::cout << "Original Data value_char: " << data.value_char << std::endl;

  std::cout << std::endl;

  std::cout << "Deserialized Result: " << result << std::endl;
  std::cout << "Deserialized Result value_long: " << result->value_long
            << std::endl;
  std::cout << "Deserialized Result value_int: " << result->value_int
            << std::endl;
  std::cout << "Deserialized Result value_char: " << result->value_char
            << std::endl;

  std::cout << std::endl;

  if (&data == result)
    std::cout << "Pointers are equal." << std::endl;
  else
    std::cout << "POINTERS ARE NOT EQUAL." << std::endl;

  return 0;
}

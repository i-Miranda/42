/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:35:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/29 23:15:12 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void) {
  std::cout << "--- 1. Basic tests ---" << std::endl;
  Array<int> array_empty;
  Array<int> array_int(5);

  array_int[0] = 10;
  array_int[1] = 11;
  array_int[2] = 12;
  array_int[3] = 13;
  array_int[4] = 14;

  std::cout << "array_empty size: " << array_empty.size() << std::endl;
  std::cout << "array_int size: " << array_int.size() << std::endl;
  for (unsigned int i = 0; i < array_int.size(); i++) {
    std::cout << "array_int[" << i << "]: " << array_int[i] << std::endl;
  }

  std::cout << std::endl;

  std::cout << "--- 2. Exceptions tests ---" << std::endl;
  try {
    std::cout << "Trying to access an empty array (array_empty[0]): "
              << array_empty[0] << std::endl;
  } catch (Array<int>::IndexOutOfBoundsException const &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  try {
    std::cout
        << "Trying to access an invalid position in an array (array_int[5]): "
        << array_int[5] << std::endl;
  } catch (Array<int>::IndexOutOfBoundsException const &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  std::cout << "--- 3. Deep copy tests ---" << std::endl;
  Array<int> array_copy(array_int);

  std::cout << "array_copy size: " << array_copy.size() << std::endl;
  for (unsigned int i = 0; i < array_copy.size(); i++) {
    std::cout << "array_copy[" << i << "]: " << array_copy[i] << std::endl;
  }
  std::cout << std::endl;

  array_copy[0] = 10000;
  array_copy[1] = 10001;
  array_copy[2] = 10002;
  array_copy[3] = 10003;
  array_copy[4] = 10004;

  std::cout << "array_copy size: " << array_copy.size() << std::endl;
  for (unsigned int i = 0; i < array_copy.size(); i++) {
    std::cout << "array_copy[" << i << "]: " << array_copy[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "array_int size: " << array_int.size() << std::endl;
  for (unsigned int i = 0; i < array_int.size(); i++) {
    std::cout << "array_int[" << i << "]: " << array_int[i] << std::endl;
  }

  std::cout << std::endl;

  std::cout << "--- 4. Assignment operator tests ---" << std::endl;

  Array<int> array_assigned;

  array_assigned = array_int;

  std::cout << "array_assigned[0]: " << array_assigned[0] << std::endl;
  std::cout << "array_int[0]: " << array_int[0] << std::endl;

  array_assigned[0] = 50000;

  std::cout << "array_assigned[0]: " << array_assigned[0] << std::endl;
  std::cout << "array_int[0]: " << array_int[0] << std::endl;

  std::cout << std::endl;

  std::cout << "--- 5. Complex type tests (std::string) ---" << std::endl;
  Array<std::string> array_str(2);

  array_str[0] = "Hello";
  array_str[1] = "World";

  std::cout << "Printing array_str[0] + array_str[1]: " << array_str[0] << " "
            << array_str[1] << std::endl;
  return 0;
}

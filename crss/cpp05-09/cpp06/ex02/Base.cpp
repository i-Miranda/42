/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:45:49 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/07 13:45:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Empty.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base *generate(void) {
  const int random_value = std::rand();

  Base *result;
  if (random_value < (RAND_MAX / 3))
    result = new A;
  else if (random_value < (RAND_MAX / 3) * 2)
    result = new B;
  else
    result = new C;
  return result;
}

void identify(Base *p) {
  if (p == NULL) {
    std::cout << "Pointer is null." << std::endl;
    return;
  }
  if (dynamic_cast<A *>(p)) {
    std::cout << "Pointer is of type A." << std::endl;
    return;
  }
  if (dynamic_cast<B *>(p)) {
    std::cout << "Pointer is of type B." << std::endl;
    return;
  }
  if (dynamic_cast<C *>(p)) {
    std::cout << "Pointer is of type C." << std::endl;
    return;
  }
  std::cout << "Pointer is of type Base." << std::endl;
}

void identify(Base &p) {
  try {
    dynamic_cast<A &>(p);
    std::cout << "Reference is of type A." << std::endl;
    return;
  } catch (...) {
  }

  try {
    dynamic_cast<B &>(p);
    std::cout << "Reference is of type B." << std::endl;
    return;
  } catch (...) {
  }

  try {
    dynamic_cast<C &>(p);
    std::cout << "Reference is of type C." << std::endl;
    return;
  } catch (...) {
  }

  std::cout << "Reference is of type Base." << std::endl;
}

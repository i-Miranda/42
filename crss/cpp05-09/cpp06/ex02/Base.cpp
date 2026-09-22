/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:45:49 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/22 18:37:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
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
    std::cout << "NULL";
    return;
  }
  if (dynamic_cast<A *>(p)) {
    std::cout << "A";
    return;
  }
  if (dynamic_cast<B *>(p)) {
    std::cout << "B";
    return;
  }
  if (dynamic_cast<C *>(p)) {
    std::cout << "C";
    return;
  }
  std::cout << "Base";
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B";
    return;
  } catch (...) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C";
    return;
  } catch (...) {
  }

  std::cout << "Base";
}

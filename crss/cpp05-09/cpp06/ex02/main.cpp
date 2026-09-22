/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:45:44 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/22 18:46:15 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
  std::srand(std::time(NULL));

  std::cout << "--- Random generation ---" << std::endl;
  for (int i = 1; i < 6; i++) {
    Base *p = generate();
    std::cout << i << ": Generated Reference is of type: ";
    identify(p);
    std::cout << std::endl;
    std::cout << i << ": Generated Pointer is of type: ";
    identify(*p);
    std::cout << std::endl;
    delete p;
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << "--- Explicit tests ---" << std::endl;
  Base *a = new A;
  Base *b = new B;
  Base *c = new C;

  std::cout << "A: Reference is of type: ";
  identify(a);
  std::cout << std::endl;
  std::cout << "A: Pointer is of type: ";
  identify(*a);
  std::cout << std::endl;
  std::cout << "B: Reference is of type: ";
  identify(b);
  std::cout << std::endl;
  std::cout << "B: Pointer is of type: ";
  identify(*b);
  std::cout << std::endl;
  std::cout << "C: Reference is of type: ";
  identify(c);
  std::cout << std::endl;
  std::cout << "C: Pointer is of type: ";
  identify(*c);
  std::cout << std::endl;

  delete a;
  delete b;
  delete c;
}

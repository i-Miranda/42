/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:45:44 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/07 13:45:45 by ivmirand         ###   ########.fr       */
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
  for (int i = 0; i < 6; i++) {
    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;
    std::cout << std::endl;
  }

  std::cout << "--- Explicit tests ---" << std::endl;
  Base *a = new A;
  Base *b = new B;
  Base *c = new C;

  identify(a);
  identify(*a);
  identify(b);
  identify(*b);
  identify(c);
  identify(*c);

  delete a;
  delete b;
  delete c;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:10:20 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 22:07:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
  std::cout << "--- 1. Basic tests ---" << std::endl;

  Span sp = Span(5);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << std::endl;

  std::cout << "--- 2. Random Big Span test ---" << std::endl;

  std::vector<int> BigVector(10000);
  std::srand(std::time(NULL));
  std::generate(BigVector.begin(), BigVector.end(), std::rand);

  Span BigSpan(10000);
  BigSpan.addRange(BigVector.begin(), BigVector.end());

  std::cout << BigSpan.shortestSpan() << std::endl;
  std::cout << BigSpan.longestSpan() << std::endl;

  std::cout << std::endl;

  std::cout << "--- 3. Copy & Assignment test ---" << std::endl;

  Span FirstSpan(4);

  FirstSpan.addNumber(100);
  FirstSpan.addNumber(200);
  FirstSpan.addNumber(300);

  Span CopySpan(FirstSpan);
  Span AssignedSpan(2);
  AssignedSpan = FirstSpan;

  std::cout << "FirstSpan longest span: " << FirstSpan.longestSpan()
            << std::endl;
  std::cout << "CopySpan longest span: " << CopySpan.longestSpan() << std::endl;
  std::cout << "AssignedSpan longest span: " << AssignedSpan.longestSpan()
            << std::endl;

  std::cout << std::endl;

  std::cout << "--- 4. Exceptions tests ---" << std::endl;

  try {
    Span ExceptionSpan(5);
    ExceptionSpan.addNumber(1);
    ExceptionSpan.shortestSpan();
  } catch (Span::MinElementsException const &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Span ExceptionSpan(5);
    ExceptionSpan.addNumber(1);
    ExceptionSpan.longestSpan();
  } catch (Span::MinElementsException const &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Span ExceptionSpan(2);
    ExceptionSpan.addNumber(1);
    ExceptionSpan.addNumber(2);
    ExceptionSpan.addNumber(3);
  } catch (Span::MaxCapacityException const &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Span ExceptionSpan(2);
    ExceptionSpan.addNumber(1);
    ExceptionSpan.addNumber(2);
    std::cout << ExceptionSpan[5] << std::endl;
  } catch (Span::IndexOutOfRangeException const &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}

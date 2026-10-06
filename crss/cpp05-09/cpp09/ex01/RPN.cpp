/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:59:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/06 13:28:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <stdexcept>

RPN::RPN(void) {}

RPN::RPN(std::string const &input) {
  for (size_t i = 0; i < input.length(); i++) {
    char c = input[i];

    if (c == ' ')
      continue;

    if (c >= '0' && c <= '9') {
      m_stack.push(c - '0');
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      if (m_stack.size() < 2)
        throw std::runtime_error("Error");

      int b = m_stack.top();
      m_stack.pop();
      int a = m_stack.top();
      m_stack.pop();

      if (c == '+')
        m_stack.push(a + b);
      else if (c == '-')
        m_stack.push(a - b);
      else if (c == '*')
        m_stack.push(a * b);
      else if (c == '/') {
        if (b == 0)
          throw std::runtime_error("Error: division by zero");
        m_stack.push(a / b);
      }
    } else {
      throw std::runtime_error("Error");
    }
  }

  if (m_stack.size() != 1)
    throw std::runtime_error("Error");

  std::cout << m_stack.top() << std::endl;
}

RPN::RPN(RPN const &src) { *this = src; }

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &src) {
  if (this != &src)
    m_stack = src.m_stack;
  return *this;
}

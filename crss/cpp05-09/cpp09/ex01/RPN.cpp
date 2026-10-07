/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:59:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/07 11:16:04 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stdexcept>

void RPN::clear_stack(void) {
  while (!m_stack.empty())
    m_stack.pop();
}

bool RPN::is_single_digit(char c) const { return (c >= '0' && c <= '9'); }

bool RPN::is_operator(char c) const {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::perform_operation(int a, char oper, int b) {
  switch (oper) {
  case '+':
    return (a + b);
  case '-':
    return (a - b);
  case '*':
    return (a * b);
  case '/':
    if (b == 0)
      throw std::runtime_error("Error");
    return (a / b);
  default:
    throw std::runtime_error("Error");
  }
}

RPN::RPN(void) {}

RPN::RPN(RPN const &src) { *this = src; }

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &src) {
  if (this != &src)
    m_stack = src.m_stack;
  return *this;
}

int RPN::calculate(std::string const &input) {
  clear_stack();
  for (size_t i = 0; i < input.length(); i++) {
    char c = input[i];

    if (c == ' ')
      continue;

    if (is_single_digit(c)) {
      m_stack.push(c - '0');
    } else if (is_operator(c)) {
      if (m_stack.size() < 2)
        throw std::runtime_error("Error");

      int b = m_stack.top();
      m_stack.pop();
      int a = m_stack.top();
      m_stack.pop();

      m_stack.push(perform_operation(a, c, b));
    } else {
      throw std::runtime_error("Error");
    }
  }
  if (m_stack.size() != 1)
    throw std::runtime_error("Error");

  return m_stack.top();
}

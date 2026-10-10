/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 12:59:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/10 12:13:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cctype>
#include <climits>
#include <stdexcept>

void RPN::clear_stack(void) {
  while (!m_stack.empty())
    m_stack.pop();
}

bool RPN::is_operator(char c) const {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::perform_operation(int a, char oper, int b) {
  long result;
  switch (oper) {
  case '+':
    result = static_cast<long>(a) + b;
    break;
  case '-':
    result = static_cast<long>(a) - b;
    break;
  case '*':
    result = static_cast<long>(a) * b;
    break;
  case '/':
    if (b == 0 || (a == INT_MIN && b == -1))
      throw std::runtime_error("Error");
    result = a / b;
    break;
  default:
    throw std::runtime_error("Error");
  }

  if (result < INT_MIN || result > INT_MAX)
    throw std::runtime_error("Error");
  return static_cast<int>(result);
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

    if (std::isspace(static_cast<unsigned char>(c)))
      continue;

    if (std::isdigit(static_cast<unsigned char>(c))) {
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

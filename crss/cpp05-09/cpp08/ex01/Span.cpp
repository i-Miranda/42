/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:06:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 14:22:52 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : m_max_size(0), m_numbers() {}

Span::Span(unsigned int N)
    : m_max_size(static_cast<std::size_t>(N)), m_numbers() {
  m_numbers.reserve(m_max_size);
}

Span::Span(Span const &src) { *this = src; }

Span::~Span() {}

Span &Span::operator=(Span const &src) {
  if (this != &src) {
    m_max_size = src.m_max_size;
    m_numbers = src.m_numbers;
  }
  return *this;
}

int const &Span::operator[](std::size_t n) const {
  if (n >= m_numbers.size())
    throw Span::IndexOutOfRangeException();
  return m_numbers[n];
}

int &Span::operator[](std::size_t n) {
  return const_cast<int &>(static_cast<Span const &>(*this)[n]);
}

void Span::addNumber(int number) {
  if (m_numbers.size() >= m_max_size)
    throw Span::MaxCapacityException();
  m_numbers.push_back(number);
}

int Span::shortestSpan() const {
  if (m_numbers.size() < 2)
    throw Span::MinElementsException();

  std::vector<int> sorted(m_numbers);
  std::sort(sorted.begin(), sorted.end());

  int shortest = sorted[1] - sorted[0];

  for (std::size_t i = 2; i < sorted.size(); i++) {
    int distance = sorted[i] - sorted[i - 1];

    if (distance < shortest)
      shortest = distance;
  }
  return shortest;
}

int Span::longestSpan() const {
  if (m_numbers.size() < 2)
    throw Span::MinElementsException();

  int lowest = *std::min_element(m_numbers.begin(), m_numbers.end());
  int highest = *std::max_element(m_numbers.begin(), m_numbers.end());

  return highest - lowest;
}

std::size_t const &Span::size() const { return m_max_size; }

char const *Span::MaxCapacityException::what() const throw() {
  return "Span at max capacity.";
}

char const *Span::MinElementsException::what() const throw() {
  return "Span needs at least two elements to search.";
}

char const *Span::IndexOutOfRangeException::what() const throw() {
  return "The requested index out of the Span's current range.";
}

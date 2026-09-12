/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:06:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/12 20:13:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <iostream>

Span::Span() : m_count(0), m_max(0), m_elements(NULL) {}

Span::Span(unsigned int N) : m_count(0), m_max(N), m_elements(new int[N]()) {}

Span::Span(const Span &src) {
  if (this != &src)
    *this = src;
}
Span::~Span() { delete[] m_elements; }

Span &Span::operator=(const Span &src) {
  m_count = src.m_count;
  m_max = src.m_max;
  m_elements = new int[m_count]();
  for (unsigned int i = 0; i < m_count; i++) {
    m_elements[i] = src.m_elements[i];
  }
  return *this;
}

int *Span::findLowest() const {
  if (m_count <= 1)
    throw MinElementsException();
  int *lowest = &m_elements[0];
  for (unsigned int curr = 0; curr < m_count; ++curr) {
    if (m_elements[curr] < *lowest)
      lowest = &m_elements[curr];
  }
  return lowest;
}

int *Span::findHighest() const {
  if (m_count <= 1)
    throw MinElementsException();
  int *highest = &m_elements[0];
  for (unsigned int curr = 0; curr < m_count; ++curr) {
    if (m_elements[curr] > *highest)
      highest = &m_elements[curr];
  }
  return highest;
}

int Span::getSpan(int &first, int &last) const {
  if (first >= last)
    return first - last;
  return last - first;
}

void Span::addNumber(int number) {
  if (m_count >= m_max)
    throw MaxCapacityException();
  m_elements[m_count] = number;
  m_count++;
}

template <typename InputIterator>
void addRange(InputIterator first, InputIterator last) {}

int Span::shortestSpan() const {
  int shortestSpan = longestSpan();
  for (unsigned int currentPos = 0; currentPos < m_count; currentPos++) {
    int first_val = m_elements[currentPos];
    for (unsigned int nextPos = currentPos + 1; nextPos < m_count; nextPos++) {
      int next_val = m_elements[nextPos];
      int currentSpan = getSpan(first_val, next_val);
      if (currentSpan < shortestSpan)
        shortestSpan = currentSpan;
    }
  }
  return shortestSpan;
}

int Span::longestSpan() const {
  int first;
  int last;

  try {
    first = *findHighest();
    last = *findLowest();
  } catch (Span::MinElementsException &e) {
    std::cout << e.what() << std::endl;
  }

  return getSpan(first, last);
}

const char *Span::MaxCapacityException::what() const throw() {
  return "Span at max capacity.";
}

const char *Span::MinElementsException::what() const throw() {
  return "Span needs at least two elements to search.";
}

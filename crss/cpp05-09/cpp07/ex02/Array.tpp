/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:35:43 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/29 16:42:38 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <cstddef>

template <typename T> Array<T>::Array() : m_count(0), m_elements(NULL) {}

template <typename T>
Array<T>::Array(unsigned int const n)
    : m_count(n), m_elements(n > 0 ? new T[n] : NULL) {}

template <typename T>
Array<T>::Array(Array<T> const &src) : m_count(0), m_elements(NULL) {
  *this = src;
}

template <typename T> Array<T>::~Array() {
  delete[] m_elements;
  m_elements = NULL;
}

template <typename T>
T const &Array<T>::operator[](unsigned int const pos) const {
  if (pos >= m_count)
    throw IndexOutOfBoundsException();
  return m_elements[pos];
}

template <typename T> T &Array<T>::operator[](unsigned int const pos) {
  return const_cast<T &>(static_cast<Array<T> const &>(*this)[pos]);
}

template <typename T> Array<T> &Array<T>::operator=(Array<T> const &src) {
  if (this != &src) {
    T *temp_elements(src.m_elements);
    for (unsigned int i = 0; i < src.m_count; i++) {
      temp_elements[i] = src.m_elements[i];
    }
    m_count = src.m_count;
    m_elements = temp_elements;
    delete[] temp_elements;
    temp_elements = NULL;
  }
  return *this;
}

template <typename T> unsigned int Array<T>::size() const { return m_count; }

template <typename T>
Array<T>::IndexOutOfBoundsException::IndexOutOfBoundsException(void) {}

template <typename T>
Array<T>::IndexOutOfBoundsException::IndexOutOfBoundsException(
    IndexOutOfBoundsException const &src) {
  *this = src;
}

template <typename T>
Array<T>::IndexOutOfBoundsException::~IndexOutOfBoundsException(void) throw() {}

template <typename T>
typename Array<T>::IndexOutOfBoundsException &
Array<T>::IndexOutOfBoundsException::operator=(
    IndexOutOfBoundsException const &src) {
  (void)src;
  return *this;
}

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what(void) const throw() {
  return "Array index out of bounds.";
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:35:43 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/12 21:09:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <cstddef>

template <typename T> Array<T>::Array() : m_count(0), m_elements(NULL) {}

template <typename T>
Array<T>::Array(unsigned int const n) : m_count(n), m_elements(new T[n]()) {}

template <typename T> Array<T>::Array(const Array<T> &src) {
  if (*this != src)
    *this = src;
}

template <typename T> Array<T>::~Array() { delete m_elements; }

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &src) {
  m_count = src.m_count;
  m_elements = src.m_elements;
  return this;
}

template <typename T> T &Array<T>::operator[](unsigned int const pos) {
  if (pos >= m_count)
    return m_elements[m_count - 1];
  return m_elements[pos];
}

template <typename T> unsigned int Array<T>::size() const { return m_count; }

#endif

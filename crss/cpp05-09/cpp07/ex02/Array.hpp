/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:35:38 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/23 11:41:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {
private:
  unsigned int m_count;
  T *m_elements;

public:
  Array();
  Array(unsigned int const n);
  Array(Array<T> const &src);
  ~Array();

  Array<T> &operator=(Array<T> const &src);
  T &operator[](unsigned int const pos);

  unsigned int size() const;
};

#include "Array.tpp"

#endif

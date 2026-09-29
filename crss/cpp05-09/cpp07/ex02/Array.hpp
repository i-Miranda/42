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

#include <exception>

template <typename T> class Array {
private:
  unsigned int m_count;
  T *m_elements;

public:
  Array(void);
  Array(unsigned int const n);
  Array(Array<T> const &src);
  ~Array(void);

  Array<T> &operator=(Array<T> const &src);

  T &operator[](unsigned int const pos);
  T const &operator[](unsigned int const pos) const;

  unsigned int size() const;

  class IndexOutOfBoundsException : public std::exception {
	public:
		IndexOutOfBoundsException(void);
		IndexOutOfBoundsException(IndexOutOfBoundsException const &src);
		~IndexOutOfBoundsException(void) throw();

		IndexOutOfBoundsException &operator=(IndexOutOfBoundsException const &src);

		virtual char const *what(void) const throw();
  };
};

#include "Array.tpp"

#endif

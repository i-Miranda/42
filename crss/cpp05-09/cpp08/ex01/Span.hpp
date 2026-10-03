/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:06:19 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 15:09:38 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <exception>
#include <vector>

class Span {
private:
  std::size_t m_max_size;
  std::vector<int> m_numbers;

public:
  Span();
  Span(unsigned int N);
  Span(Span const &src);
  ~Span();

  Span &operator=(Span const &src);

  int &operator[](std::size_t n);
  int const &operator[](std::size_t n) const;

  void addNumber(int number);

  template <typename InputIterator>
  void addRange(InputIterator first, InputIterator last);

  int shortestSpan() const;
  int longestSpan() const;

  std::size_t const &size() const;

  class MaxCapacityException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

  class MinElementsException : public std::exception {
  public:
    virtual char const *what() const throw();
  };

  class IndexOutOfRangeException : public std::exception {
  public:
    virtual char const *what() const throw();
  };
};

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
  while (first != last) {
    addNumber(*first);
    first++;
  }
}

#endif

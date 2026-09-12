/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 18:06:19 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/12 20:15:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

class Span {
private:
  unsigned int m_count;
  unsigned int m_max;
  int *m_elements;

  Span();
  int *findLowest() const;
  int *findHighest() const;
  int getSpan(int &first, int &last) const;

public:
  Span(unsigned int N);
  Span(const Span &src);
  ~Span();
  Span &operator=(const Span &src);

  void addNumber(int number);

  template <typename InputIterator>
  void addRange(InputIterator first, InputIterator last);

  int shortestSpan() const;
  int longestSpan() const;

  class MaxCapacityException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class MinElementsException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 20:20:21 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/12 21:13:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack();
  MutantStack(const MutantStack<T> &src);
  ~MutantStack();

  MutantStack<T> &operator=(const MutantStack<T> &src);
};

#include "MutantStack.tpp"

#endif

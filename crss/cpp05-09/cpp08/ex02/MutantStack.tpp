/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 20:20:10 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 15:09:20 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T> MutantStack::MutantStack(void) {
  std::cout << "Default MutantStack Constructor Called" << std::endl;
}

template <typename T> MutantStack::MutantStack(MutantStack const &src) {
  std::cout << "MutantStack Copy Constructor Called" << std::endl;
  *this = src;
}

template <typename T> MutantStack::~MutantStack(void) {
  std::cout << "MutantStack Destructor Called" << std::endl;
}

template <typename T>
MutantStack &MutantStack::operator=(MutantStack<T> const &src) {
  std::cout << "MutantStack Assignment Operator Called" << std::endl;
  if (this != &src)
    std::stack<T>::operator=(src);
  return *this;
}

#endif

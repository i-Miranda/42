/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 20:20:10 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 15:36:06 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

#include <iostream>

template <typename T> MutantStack<T>::MutantStack(void) : std::stack<T>() {
  std::cout << "Default MutantStack Constructor Called" << std::endl;
}

template <typename T> MutantStack<T>::MutantStack(MutantStack const &src) {
  std::cout << "MutantStack Copy Constructor Called" << std::endl;
  *this = src;
}

template <typename T> MutantStack<T>::~MutantStack(void) {
  std::cout << "MutantStack Destructor Called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src) {
  std::cout << "MutantStack Assignment Operator Called" << std::endl;
  if (this != &src)
    std::stack<T>::operator=(src);
  return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return this->c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
  return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return this->c.end();
}

#endif

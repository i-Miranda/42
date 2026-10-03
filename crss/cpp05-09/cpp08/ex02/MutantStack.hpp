/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 20:20:21 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 15:19:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack(void);
  MutantStack(MutantStack const &src);
  ~MutantStack(void);

  MutantStack &operator=(MutantStack const &src);

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  iterator begin();
  iterator end();

  const_iterator begin() const;
  const_iterator end() const;
};

#include "MutantStack.tpp"

#endif

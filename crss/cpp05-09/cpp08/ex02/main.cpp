/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 20:20:26 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/03 22:27:37 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main(void) {
  std::cout << "--- 1. Main from Subject with Const_iterator added ---"
            << std::endl;
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  MutantStack<int> const cmstack = mstack;

  MutantStack<int>::const_iterator const_it = cmstack.begin();
  MutantStack<int>::const_iterator const_ite = cmstack.end();

  while (const_it != const_ite) {
    std::cout << *const_it << std::endl;
    ++const_it;
  }

  std::stack<int> s(mstack);

  std::cout << std::endl;

  std::cout
      << "--- 2. std::list example (Output should be the same as last) ---"
      << std::endl;
  std::list<int> list;

  list.push_back(5);
  list.push_back(17);

  std::cout << list.back() << std::endl;

  list.pop_back();

  std::cout << list.size() << std::endl;

  list.push_back(3);
  list.push_back(5);
  list.push_back(737);
  //[...]
  list.push_back(0);

  std::list<int>::iterator list_it = list.begin();
  std::list<int>::iterator list_ite = list.end();

  ++list_it;
  --list_it;

  while (list_it != list_ite) {
    std::cout << *list_it << std::endl;
    ++list_it;
  }

  std::list<int> const clist = list;

  std::list<int>::const_iterator const_list_it = clist.begin();
  std::list<int>::const_iterator const_list_ite = clist.end();

  while (const_list_it != const_list_ite) {
    std::cout << *const_list_it << std::endl;
    ++const_list_it;
  }

  return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:33:57 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/12 16:34:01 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main(void) {
  {
    std::deque<int> int_deque;

    int_deque.push_back(1);
    int_deque.push_back(2);
    int_deque.push_back(3);
    int_deque.push_back(4);
    int_deque.push_back(5);

    try {
      std::deque<int>::iterator it = easyfind(int_deque, 42);
      std::cout << "Found: " << *it << std::endl;
    } catch (TNotFoundException &e) {
      std::cout << "Not found: 42 " << e.what() << std::endl;
    }

    try {
      std::deque<int>::iterator it = easyfind(int_deque, 3);
      std::cout << "Found: " << *it << std::endl;
    } catch (TNotFoundException &e) {
      std::cout << "Not found: 3 " << e.what() << std::endl;
    }
  }

  {
    std::list<int> int_list;

    int_list.push_back(11);
    int_list.push_back(12);
    int_list.push_back(23);
    int_list.push_back(34);
    int_list.push_back(45);

    try {
      std::list<int>::iterator it = easyfind(int_list, 42);
      std::cout << "Found: " << *it << std::endl;
    } catch (TNotFoundException &e) {
      std::cout << "Not found: 42 " << e.what() << std::endl;
    }

    try {
      std::list<int>::iterator it = easyfind(int_list, 34);
      std::cout << "Found: " << *it << std::endl;
    } catch (TNotFoundException &e) {
      std::cout << "Not found: 34 " << e.what() << std::endl;
    }
  }

  {
    std::vector<int> int_vect;

    int_vect.push_back(10);
    int_vect.push_back(21);
    int_vect.push_back(32);
    int_vect.push_back(43);
    int_vect.push_back(54);

    try {
      std::vector<int>::iterator it = easyfind(int_vect, 42);
      std::cout << "Found: " << *it << std::endl;
    } catch (TNotFoundException &e) {
      std::cout << "Not found: 42 " << e.what() << std::endl;
    }

    try {
      std::vector<int>::iterator it = easyfind(int_vect, 43);
      std::cout << "Found: " << *it << std::endl;
    } catch (TNotFoundException &e) {
      std::cout << "Not found: 43 " << e.what() << std::endl;
    }
  }

  return (0);
}

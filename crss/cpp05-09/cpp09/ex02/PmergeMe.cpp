/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/07 13:45:51 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &src) { *this = src; }

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
  if (this != &src) {
    m_deque = src.m_deque;
    m_vector = src.m_vector;
  }
  return *this;
}

void PmergeMe::sort(int argc, char *argv[]) {}

void PmergeMe::printResults(void) {
  std::cout << "Before: \t" << input << std::endl;
  std::cout << "After: \t" << output << std::endl;
  std::cout << "Time to process a range of \t" << pmerge.getDeque().count()
            << " elements with std::deque : " << end_deque << std::endl;
  std::cout << "Time to process a range of \t" << pmerge.getVector().count()
            << " elements with std::vector : " << end_vector << std::endl;
}

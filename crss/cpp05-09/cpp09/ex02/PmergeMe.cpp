/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/08 10:43:07 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>

bool PmergeMe::is_numeric(std::string const &str) {
  return !str.empty() &&
         str.find_first_not_of("0123456789") == std::string::npos;
}

void PmergeMe::sort_deque(int argc, char *argv[]) {
  m_start_deque = std::clock();
  for (int i = 1; i < argc; i++)
    m_deque.push_back(std::atoi(argv[i]));
  m_end_deque = std::clock();
}

void PmergeMe::sort_vector(int argc, char *argv[]) {
  m_start_vector = std::clock();
  for (int i = 1; i < argc; i++)
    m_vector.push_back(std::atoi(argv[i]));
  m_end_vector = std::clock();
}

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

void PmergeMe::parseAndPrintArgs(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    if (!is_numeric(argv[i]) || std::strtol(argv[i], NULL, 10) > INT_MAX)
      throw std::runtime_error("Error");
  }
  std::cout << "Before: ";
  for (int i = 1; i < argc; i++)
    std::cout << argv[i] << (i == argc - 1 ? "" : " ");
  std::cout << std::endl;
}

void PmergeMe::sort(int argc, char *argv[]) {
  sort_vector(argc, argv);
  sort_deque(argc, argv);
}

void PmergeMe::printResults(void) {
  std::cout << "After:  ";
  std::cout << std::endl;
  std::cout << "Time to process a range of \t" << m_deque.size()
            << " elements with std::deque : " << m_end_deque << std::endl;
  std::cout << "Time to process a range of \t" << m_vector.size()
            << " elements with std::vector : " << m_end_vector << std::endl;
}

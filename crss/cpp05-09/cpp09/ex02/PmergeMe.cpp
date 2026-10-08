/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/08 13:12:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <sstream>

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
  m_input.clear();

  for (int i = 1; i < argc; i++) {
    std::istringstream input(argv[i]);
    std::string token;
    bool found = false;

    while (input >> token) {
      found = true;
      if (!is_numeric(token))
        throw std::runtime_error("Error");

      long value = std::strtol(token.c_str(), NULL, 10);
      if (value < 0 || value > INT_MAX)
        throw std::runtime_error("Error");

      m_input.push_back(static_cast<int>(value));
    }

    if (!found)
      throw std::runtime_error("Error");
  }

  std::cout << "Before: ";
  for (size_t i = 0; i < m_input.size(); i++)
    std::cout << m_input[i] << (i + 1 == m_input.size() ? "" : " ");
  std::cout << std::endl;
}

void PmergeMe::sort(int argc, char *argv[]) {
  sort_vector(argc, argv);
  sort_deque(argc, argv);
}

void PmergeMe::printResults(void) {
  std::cout << "After:  ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << m_deque.size()
            << " elements with std::deque : " << m_end_deque << std::endl;
  std::cout << "Time to process a range of " << m_vector.size()
            << " elements with std::vector : " << m_end_vector << std::endl;
}

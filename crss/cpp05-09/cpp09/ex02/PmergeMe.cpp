/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/09 13:40:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cctype>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>

template <typename T> void PmergeMe::parseArgs(int argc, char *argv[], T &out) {
  out.clear();

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

      out.push_back(static_cast<int>(value));
    }

    if (!found)
      throw std::runtime_error("Error");
  }
}

bool PmergeMe::is_numeric(std::string const &str) {
  return !str.empty() &&
         str.find_first_not_of("0123456789") == std::string::npos;
}

template <typename T>
void PmergeMe::collectPairs(
    T const &values,
    std::vector<std::pair<typename T::value_type, typename T::value_type> >
        &pairs,
    T &winners, bool &hasStray, typename T::value_type &stray) {
  hasStray = false;
  typename T::const_iterator it = values.begin();
  while (it != values.end()) {
    typename T::value_type first = *it++;
    if (it == values.end()) {
      stray = first;
      hasStray = true;
      break;
    }
    typename T::value_type second = *it++;
    if (second < first)
      std::swap(first, second);
    pairs.push_back(std::pair<typename T::value_type, typename T::value_type>(
        first, second));
    winners.push_back(second);
  }
}

template <typename T>
void PmergeMe::sortPairsByWinner(
    std::vector<std::pair<typename T::value_type,
                          typename T::value_type> > const &pairs,
    T &winners,
    std::vector<std::pair<typename T::value_type, typename T::value_type> >
        &sortedPairs) {
  // Recursively sort the larger value from each pair
  fordJohnson(winners);

  // Restore each winner's original pair, preserving the pair relationship.
  std::vector<bool> used(pairs.size(), false);
  for (std::size_t i = 0; i < winners.size(); i++) {
    std::size_t j = 0;
    while (j < pairs.size() && (used[j] || pairs[j].second != winners[i]))
      j++;
    if (j == pairs.size())
      throw std::runtime_error("Error");
    used[j] = true;
    sortedPairs.push_back(pairs[j]);
  }
}

template <typename T>
void PmergeMe::buildMainChain(
    std::vector<std::pair<typename T::value_type,
                          typename T::value_type> > const &sortedPairs,
    T &chain) {
  // The first smaller value starts the chain. All winners follow it.
  chain.push_back(sortedPairs[0].first);
  for (std::size_t i = 0; i < sortedPairs.size(); i++)
    chain.push_back(sortedPairs[i].second);
}

std::vector<std::size_t> PmergeMe::makeInsertionOrder(std::size_t pairCount,
                                                      bool hasStray) {
  std::size_t const maxIndex = pairCount + (hasStray ? 1 : 0);
  std::vector<std::size_t> order;
  std::size_t previous = 1;
  std::size_t current = 3;

  // Generate Jacobsthal-based groups, inserting each group in reverse.
  while (previous < maxIndex) {
    std::size_t const top = (current < maxIndex) ? current : maxIndex;

    for (std::size_t index = top; index > previous; --index)
      order.push_back(index);

    std::size_t const next = current + 2 * previous;
    previous = current;
    current = next;
  }
  return order;
}

template <typename T>
void PmergeMe::insertPendingValues(
    T &chain,
    std::vector<std::pair<typename T::value_type,
                          typename T::value_type> > const &sortedPairs,
    bool hasStray, int stray, std::vector<std::size_t> const &insertionOrder) {
  for (std::size_t i = 0; i < insertionOrder.size(); i++) {
    std::size_t const index = insertionOrder[i];
    typename T::value_type pending;
    typename T::iterator searchEnd;

    if (index <= sortedPairs.size()) {
      // Search only before this pending value's paired winner.
      pending = sortedPairs[index - 1].first;
      searchEnd = std::lower_bound(chain.begin(), chain.end(),
                                   sortedPairs[index - 1].second);
    } else {
      // The unpaired value has no winner to limit its search range.
      if (!hasStray)
        throw std::runtime_error("Error");
      pending = stray;
      searchEnd = chain.end();
    }
    typename T::iterator position =
        std::lower_bound(chain.begin(), searchEnd, pending);
    chain.insert(position, pending);
  }
}

template <typename T> void PmergeMe::fordJohnson(T &values) {
  if (values.size() < 2)
    return;

  std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
  T winners;
  bool hasStray = false;
  typename T::value_type stray = typename T::value_type();

  collectPairs(values, pairs, winners, hasStray, stray);

  std::vector<std::pair<typename T::value_type, typename T::value_type> >
      sortedPairs;
  sortPairsByWinner(pairs, winners, sortedPairs);

  T chain;
  buildMainChain(sortedPairs, chain);

  std::vector<std::size_t> insertionOrder =
      makeInsertionOrder(sortedPairs.size(), hasStray);

  insertPendingValues(chain, sortedPairs, hasStray, stray, insertionOrder);

  values.swap(chain);
}

void PmergeMe::sort_deque(int argc, char *argv[]) {
  m_start_deque = std::clock();
  parseArgs(argc, argv, m_deque);
  fordJohnson(m_deque);
  m_end_deque = std::clock();
}

void PmergeMe::sort_vector(int argc, char *argv[]) {
  m_start_vector = std::clock();
  parseArgs(argc, argv, m_vector);
  fordJohnson(m_vector);
  m_end_vector = std::clock();
}

std::string PmergeMe::calculateAndFormatUs(std::clock_t start,
                                           std::clock_t end) {
  double const microseconds =
      static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;

  std::ostringstream out;
  out << std::fixed << std::setprecision(5) << microseconds << " us";

  std::string result = out.str();
  while (!result.empty() && result[result.size() - 1] == '0')
    result.erase(result.size() - 1);
  if (!result.empty() && result[result.size() - 1] == '.')
    result.erase(result.size() - 1);

  return result;
}

void PmergeMe::printResults(int argc, char *argv[]) {
  std::vector<int> m_input;

  parseArgs(argc, argv, m_input);
  std::cout << "Before: ";
  for (size_t i = 0; i < m_input.size(); i++)
    std::cout << m_input[i] << (i + 1 == m_input.size() ? "" : " ");
  std::cout << std::endl;
  std::cout << "After:  ";
  for (size_t i = 0; i < m_vector.size(); i++)
    std::cout << m_vector[i] << (i + 1 == m_vector.size() ? "" : " ");
  std::cout << std::endl;
  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << m_deque.size()
            << " elements with std::deque : "
            << calculateAndFormatUs(m_start_deque, m_end_deque) << std::endl;
  std::cout << "Time to process a range of " << m_vector.size()
            << " elements with std::vector : "
            << calculateAndFormatUs(m_start_vector, m_end_vector) << std::endl;
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

void PmergeMe::sort(int argc, char *argv[]) {
  sort_vector(argc, argv);
  sort_deque(argc, argv);
  if (m_vector.size() != m_deque.size() ||
      !std::equal(m_vector.begin(), m_vector.end(), m_deque.begin()))
    throw std::runtime_error("Containers produced different results.");
  printResults(argc, argv);
}

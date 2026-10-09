/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:45 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/09 13:19:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <ctime>
#include <deque>
#include <string>
#include <vector>

class PmergeMe {
private:
  std::deque<int> m_deque;
  std::vector<int> m_vector;

  std::clock_t m_start_deque;
  std::clock_t m_end_deque;
  std::clock_t m_start_vector;
  std::clock_t m_end_vector;

  bool is_numeric(std::string const &str);
  template <typename T> void parseArgs(int argc, char *argv[], T &out);

  template <typename T>
  void collectPairs(
      T const &values,
      std::vector<std::pair<typename T::value_type, typename T::value_type> >
          &pairs,
      T &winners, bool &hasStray, typename T::value_type &stray);

  template <typename T>
  void sortPairsByWinner(
      std::vector<std::pair<typename T::value_type,
                            typename T::value_type> > const &pairs,
      T &winners,
      std::vector<std::pair<typename T::value_type, typename T::value_type> >
          &sortedPairs);

  template <typename T>
  void buildMainChain(
      std::vector<std::pair<typename T::value_type,
                            typename T::value_type> > const &sortedPairs,
      T &chain);

  std::vector<std::size_t> makeInsertionOrder(std::size_t pairCount,
                                              bool hasStray);
  template <typename T>
  void insertPendingValues(
      T &chain,
      std::vector<std::pair<typename T::value_type,
                            typename T::value_type> > const &sortedPairs,
      bool hasStray, int stray, std::vector<std::size_t> const &insertionOrder);

  template <typename T> void fordJohnson(T &values);
  void sort_deque(int argc, char *argv[]);
  void sort_vector(int argc, char *argv[]);

  double calculateMs(std::clock_t start, std::clock_t end);
  void printResults(int argc, char *argv[]);

public:
  PmergeMe(void);
  PmergeMe(PmergeMe const &src);
  ~PmergeMe(void);

  PmergeMe &operator=(PmergeMe const &src);

  void sort(int argc, char *argv[]);
};

#endif

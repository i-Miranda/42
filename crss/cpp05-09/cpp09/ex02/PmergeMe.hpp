/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:45 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/08 10:38:26 by ivmirand         ###   ########.fr       */
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
  void sort_deque(int argc, char *argv[]);
  void sort_vector(int argc, char *argv[]);

public:
  PmergeMe(void);
  PmergeMe(PmergeMe const &src);
  ~PmergeMe(void);

  PmergeMe &operator=(PmergeMe const &src);

  void parseAndPrintArgs(int argc, char *argv[]);
  void sort(int argc, char *argv[]);
  void printResults(void);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:45 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/07 13:19:52 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <vector>

class PmergeMe {
private:
  std::deque<int> m_deque;
  std::vector<int> m_vector;

public:
  PmergeMe(void);
  PmergeMe(PmergeMe const &src);
  ~PmergeMe(void);

  PmergeMe &operator=(PmergeMe const &src);

  void parseArgs(int argc, char *argv[]);
  void sort(void);
  void printResults(void);
};

#endif

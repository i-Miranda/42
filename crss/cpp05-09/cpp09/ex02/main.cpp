/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:41 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/09 10:11:56 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  PmergeMe pmerge;
  std::string input;
  std::string output;

  try {
    pmerge.sort(argc, argv);
  } catch (std::exception const &e) {
    std::cerr << "Error" << std::endl;
  }

  return 0;
}

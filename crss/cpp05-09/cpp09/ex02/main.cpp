/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 12:32:41 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/08 12:39:08 by ivmirand         ###   ########.fr       */
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
    pmerge.parseAndPrintArgs(argc, argv);

    pmerge.sort(argc, argv);
    pmerge.printResults();

  } catch (std::exception const &e) {
    std::cerr << "Error" << std::endl;
  }

  return 0;
}

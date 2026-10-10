/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:13:16 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/10 13:02:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
  std::ifstream input_file;
  std::string line;

  try {
    if (argc != 2)
      throw std::runtime_error("Error: could not open file.");

    BitcoinExchange btc_exchange;

    input_file.open(argv[1]);
    if (!input_file.is_open())
      throw std::runtime_error("Error: could not open file.");

    if (!std::getline(input_file, line))
      throw std::runtime_error("Error: empty file.");
    if (line != "date | value")
      throw std::runtime_error("Error: file header is not correct format.");
    while (std::getline(input_file, line))
      btc_exchange.eval_line(line);

  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
    input_file.close();
    return 1;
  }

  input_file.close();
  return 0;
}

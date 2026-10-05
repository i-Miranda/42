/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 09:53:37 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/05 13:35:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(void) { init_database("data.csv"); }

BitcoinExchange::BitcoinExchange(std::string const &data_path) {
  init_database(data_path);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
  if (this != &src)
    m_data = src.m_data;
  return *this;
}

void BitcoinExchange::eval_line(std::string const &line) {}

float BitcoinExchange::string_to_float(std::string const &str) {
  return std::strtof(str.c_str(), NULL);
}

void BitcoinExchange::init_database(std::string const &db_path) {
  std::ifstream db_file;
  std::string line;

  db_file.open(db_path.c_str());
  if (!db_file.is_open())
    throw std::runtime_error("Error: could not retrieve the database.");
  try {
    if (!std::getline(db_file, line)) {
      db_file.close();
      throw std::runtime_error("Error: empty file.");
    }
    if (line != "date,exchange") {
      db_file.close();
      throw std::runtime_error("Error: database header is not correct format.");
    }
    while (std::getline(db_file, line)) {
      std::size_t separator;
      std::string date_str;
      std::string exchange_str;

      if (line.empty())
        continue;
      separator = line.find(',');
      if (separator == std::string::npos) {
        std::cout << "Error: invalid database line => " + line + ". "
                  << "Skipping line." << std::endl;
        continue;
      }
      date_str = line.substr(0, separator);
      exchange_str = line.substr(separator + 1);
      m_data[date_str] = string_to_float(exchange_str);
    }
  } catch (std::exception const &e) {
    throw;
  }
  db_file.close();
}

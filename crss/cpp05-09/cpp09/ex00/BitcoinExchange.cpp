/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 09:53:37 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/10 00:51:29 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
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

void BitcoinExchange::eval_line(std::string const &line) {
  std::size_t separator;
  std::string date;
  std::string value_str;
  float value;
  float exchange_rate;

  separator = line.find(" | ");
  if (separator == std::string::npos) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }
  date = line.substr(0, separator);
  if (!is_valid_date(date)) {
    std::cout << "Error: bad input => " << date << std::endl;
    return;
  }
  value_str = line.substr(separator + 3);
  if (value_str.empty()) {
    std::cout << "Error: bad input => " << line << std::endl;
    return;
  }
  try {
    value = string_to_float(value_str);
    if (value < 0) {
      std::cout << "Error: not a positive number." << std::endl;
      return;
    }
    if (value > 1000) {
      std::cout << "Error: too large a number." << std::endl;
      return;
    }
    exchange_rate = calculate_exchange_rate(date, value);
    std::cout << date << " => " << value << " = " << exchange_rate << std::endl;
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
}

void BitcoinExchange::init_database(std::string const &db_path) {
  std::ifstream db_file;
  std::string line;

  db_file.open(db_path.c_str());
  if (!db_file.is_open())
    throw std::runtime_error("Error: could not retrieve the database.");
  if (!std::getline(db_file, line)) {
    db_file.close();
    throw std::runtime_error("Error: empty file.");
  }
  if (line != "date,exchange_rate") {
    db_file.close();
    throw std::runtime_error("Error: database header is not correct format.");
  }
  while (std::getline(db_file, line)) {
    std::size_t separator;
    std::string date;
    std::string exchange_str;

    if (line.empty())
      continue;
    separator = line.find(',');
    if (separator == std::string::npos) {
      std::cout << "Error: invalid database line => " << line << std::endl;
      continue;
    }
    date = line.substr(0, separator);
    if (!is_valid_date(date)) {
      std::cout << "Error: bad input => " + date << std::endl;
      continue;
    }
    exchange_str = line.substr(separator + 1);

    try {
      float rate = string_to_float(exchange_str);
      if (rate < 0) {
        std::cout << "Error: invalid database rate => " << exchange_str
                  << std::endl;
        continue;
      }
      m_data[date] = rate;
    } catch (std::exception const &e) {
      std::cout << "Error: invalid database rate => " << line << " ("
                << e.what() << ")" << std::endl;
    }
  }
  db_file.close();
}

float BitcoinExchange::calculate_exchange_rate(std::string const &date,
                                               float value) {
  std::map<std::string, float>::const_iterator it;

  it = m_data.lower_bound(date);
  if (it != m_data.end() && it->first == date)
    return value * it->second;
  if (it == m_data.begin())
    throw std::runtime_error("Error: bad input => " + date);
  --it;
  return value * it->second;
}

bool BitcoinExchange::is_valid_date(std::string const &date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  for (std::size_t i = 0; i < date.length(); i++) {
    if (i == 4 || i == 7)
      continue;
    if (!std::isdigit(static_cast<unsigned char>(date[i])))
      return false;
  }

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30)
      return false;
  }

  if (month == 2) {
    bool is_leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (is_leap && day > 29)
      return false;
    if (!is_leap && day > 28)
      return false;
  }
  return true;
}

float BitcoinExchange::string_to_float(std::string const &str) {
  std::istringstream stream(str);
  float value;

  if (!(stream >> value))
    throw std::runtime_error("Error: invalid number => " + str);

  stream >> std::ws;
  if (!stream.eof() || value != value || value < -FLT_MAX || value > FLT_MAX)
    throw std::runtime_error("Error: invalid number => " + str);

  return value;
}

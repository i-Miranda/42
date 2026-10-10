/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 09:53:47 by ivmirand          #+#    #+#             */
/*   Updated: 2026/10/10 17:06:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> m_data;

  bool is_valid_date(std::string const &date);
  float string_to_float(std::string const &str);
  void init_database(std::string const &db_path);
  float calculate_exchange_rate(std::string const &date, float value);

public:
  BitcoinExchange(void);
  BitcoinExchange(std::string const &data_path);
  BitcoinExchange(BitcoinExchange const &src);
  ~BitcoinExchange(void);

  BitcoinExchange &operator=(BitcoinExchange const &src);

  void eval_line(std::string const &line);
};

#endif

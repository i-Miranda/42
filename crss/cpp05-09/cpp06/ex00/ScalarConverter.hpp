/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:25:50 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/20 18:36:29 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &other);
  ~ScalarConverter(void);

public:
  static void convert(std::string const &literal);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 11:53:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/07 11:53:58 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
  Serializer();
  Serializer(Serializer const &src);
  Serializer &operator=(Serializer const &src);
  ~Serializer();

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif

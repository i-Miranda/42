/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:49:16 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/30 09:38:42 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void print(T const &value) {
  std::cout << value << std::endl;
}

template <typename T>
void iter(T *addr, std::size_t const length, void *(func)(T const &)) {
  if (addr == NULL)
    return;
  for (std::size_t i = 0; i < length; i++) {
    func(addr[i]);
  }
}

#endif

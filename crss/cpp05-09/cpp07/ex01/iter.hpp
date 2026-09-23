/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:49:16 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/23 11:36:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void print(T const &value) {
  std::cout << value << std::endl;
}

template <typename T_array, typename T_func>
void iter(T_array *addr, size_t const length, T_func func) {
  if (addr == NULL || func == NULL)
    return;
  for (size_t i = 0; i < length; i++) {
    func(addr[i]);
  }
}

#endif

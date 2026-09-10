/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:49:16 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/10 13:49:17 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T_array, typename T_func>
void iter(T_array *addr, const size_t length, T_func func) {
  for (int i = 0; i < length; i++) {
    func(addr[i]);
  }
}

#endif

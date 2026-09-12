/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:34:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/13 00:03:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int to_be_found) {
  typename T::iterator it =
      std::find(container.begin(), container.end(), to_be_found);
  if (*it == to_be_found)
    return it;
  throw TNotFoundException();
}

#endif

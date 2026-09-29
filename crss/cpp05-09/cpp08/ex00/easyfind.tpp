/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:34:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/30 00:00:15 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <stdexcept>

template <typename Iterator>
Iterator findValue(Iterator begin, Iterator end, int to_be_found) {
  Iterator it = std::find(begin, end, to_be_found);
  if (it == end)
    throw std::runtime_error("Value not found.");
  return it;
}

template <typename T>
typename T::iterator easyfind(T &container, int to_be_found) {
  return findValue(container.begin(), container.end(), to_be_found);
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int to_be_found) {
  return findValue(container.begin(), container.end(), to_be_found);
}

#endif

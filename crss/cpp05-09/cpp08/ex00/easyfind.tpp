/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:34:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/23 13:14:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

#include <algorithm>

template <typename Iterator>
Iterator findValue(Iterator begin, Iterator end, int to_be_found) {
  Iterator it = std::find(begin, end, to_be_found);
  if (it == end)
    throw TNotFoundException();
  return it;
}

template <typename Container>
typename Container::iterator easyfind(Container &container, int to_be_found) {
  return findValue(container.begin(), container.end(), to_be_found);
}

template <typename Container>
typename Container::const_iterator easyfind(Container const &container,
                                            int to_be_found) {
  return findValue(container.begin(), container.end(), to_be_found);
}

#endif

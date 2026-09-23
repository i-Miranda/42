/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:34:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/23 13:14:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class TNotFoundException : public std::exception {
public:
  virtual const char *what() const throw() { return "Value not found."; }
};

template <typename Container>
typename Container::iterator easyfind(Container &container, int to_be_found);

template <typename Container>
typename Container::const_iterator easyfind(Container const &container,
                                            int to_be_found);

#include "easyfind.tpp"

#endif

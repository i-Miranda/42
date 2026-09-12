/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:34:15 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/12 16:34:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class TNotFoundException : public std::exception {
public:
  virtual const char *what() const throw() { return "Value not found."; }
};

template <typename T>
typename T::iterator easyfind(T &container, int to_be_found);

#include "easyfind.tpp"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 12:24:08 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/23 12:30:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &x, T &y) {
  T tmp = x;
  x = y;
  y = tmp;
}

template <typename T> T min(T const &x, T const &y) { return (x < y) ? x : y; }

template <typename T> T max(T const &x, T const &y) { return (x > y) ? x : y; }

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 12:24:08 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/10 12:42:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T min(const T& x, const T& y) {
	return (x <= y) ? x : y;
};

template<typename T>
T max(const T& x, const T& y) {
	return (x <= y) ? y : x;
};

#endif

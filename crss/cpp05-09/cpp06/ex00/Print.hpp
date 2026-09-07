/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:09:32 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/08 10:09:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PRINT_HPP
#define PRINT_HPP

#include "Conversions.hpp"
#include <string>

void printChar(t_conversions *conversions);
void printInt(t_conversions *conversions);
void printFloat(t_conversions *conversions);
void printDouble(t_conversions *conversions);

void printImpossible(void);

void printPseudoLiteral(std::string const &pseudo_literal);

void printConversions(t_conversions const &conversions);

#endif

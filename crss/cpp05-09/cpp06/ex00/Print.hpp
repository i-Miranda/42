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

#include "Conversions.hpp"
#include <string>

static void printChar(t_conversions *conversions);
static void printInt(t_conversions *conversions);
static void printFloat(t_conversions *conversions);
static void printDouble(t_conversions *conversions);

void printImpossible(void);

void printPseudoLiteral(std::string const &pseudo_literal);

void printConversions(t_conversions const &conversions);

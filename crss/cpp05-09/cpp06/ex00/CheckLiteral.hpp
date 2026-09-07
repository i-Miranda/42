/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PseudoLiteral.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:57:20 by ivmirand          #+#    #+#             */
/*   Updated: 2026/07/07 22:57:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHECKLITERAL_HPP
#define CHECKLITERAL_HPP

#include <string>

bool isFloatPseudoLiteral(std::string const &pseudo_literal);

bool isPseudoLiteral(std::string const &literal);

bool isLastCharF(std::string const &literal);
#endif

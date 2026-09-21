/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckLiteral.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:57:20 by ivmirand          #+#    #+#             */
/*   Updated: 2026/09/20 18:35:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKLITERAL_HPP
#define CHECKLITERAL_HPP

#include "Conversions.hpp"
#include <string>

bool isFloatPseudoLiteral(std::string const &literal);

bool isPseudoLiteral(std::string const &literal);

bool isNumericLiteral(t_conversions &c);

bool isCharLiteral(t_conversions &c);

bool isIntLiteral(t_conversions &c);

bool isLastCharF(t_conversions &c);
#endif

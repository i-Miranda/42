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

#include <string>

bool isFloatPseudoLiteral(std::string const &literal);

bool isPseudoLiteral(std::string const &literal);

bool isDecimalLiteral(std::string const &literal);

bool isCharLiteral(std::string const &literal);

bool hasFloatSuffix(std::string const &literal);

#endif

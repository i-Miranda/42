/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:57:30 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/27 22:19:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : m_type(type) {}

Weapon::~Weapon(void) {}

const std::string &Weapon::getType(void) const {
	return (m_type); 
}

void Weapon::setType(const std::string &type) {
	m_type = type; 
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:57:19 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 03:01:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : m_name(name) {}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon &weapon) {
	m_weapon = &weapon; 
}

void HumanB::attack(void) const {
  std::cout << m_name << " attacks with " << m_weapon->getType()
            << std::endl;
}

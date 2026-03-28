/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:57:14 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/28 03:01:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
    : m_name(name),
	m_weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const {
  std::cout << m_name << " attacks with " << m_weapon.getType()
            << std::endl;
}

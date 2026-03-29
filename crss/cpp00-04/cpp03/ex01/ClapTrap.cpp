/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:07:49 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/29 23:13:17 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :	m_name("Generic ClapTrap"),
							m_hit_points(10),
							m_energy_points(10),
							m_attack_damage(0) {
	std::cout << m_name << "'s ClapTrap Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : m_name(name),
								m_hit_points(10),
								m_energy_points(10),
								m_attack_damage(0) {
	std::cout << m_name << "'s ClapTrap Name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) : m_name(src.m_name),
								m_hit_points(src.m_hit_points),
								m_energy_points(src.m_energy_points),
								m_attack_damage(src.m_attack_damage) {
	std::cout << m_name << "'s ClapTrap Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << m_name << "'s ClapTrap Destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src) {
	std::cout << m_name << "'s ClapTrap Copy assignment operator called." << std::endl;
	m_name = src.m_name;
	m_hit_points = src.m_hit_points;
	m_energy_points = src.m_energy_points;
	m_attack_damage = src.m_attack_damage;
	return *this;
}

void		ClapTrap::attack(const std::string& target) {
	if (m_hit_points > 0 && m_energy_points >= 1) {
		m_energy_points--;
		std::cout << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage!" << std::endl;
		if (m_energy_points < 0)
			m_energy_points = 0;
	}
	else if (m_hit_points > 0)
		std::cout << m_name << " doesn't have enough energy points left." << std::endl;
	else
		std::cout << m_name << " is dead. " << std::endl;
}

void		ClapTrap::takeDamage(unsigned int	amount) {
	if (m_hit_points > 0) {
		m_hit_points -= amount;
		std::cout << m_name << " takes " << amount << " points of damage!" << std::endl;
		if (m_hit_points < 0)
			m_hit_points = 0;
	}
}

void		ClapTrap::beRepaired(unsigned int	amount) {
	if (m_hit_points > 0 && m_energy_points >= 1) {
		m_hit_points += amount;
		m_energy_points--;
		std::cout << m_name << " repairs " << amount << " points of damage!" << std::endl;
		if (m_energy_points < 0)
			m_energy_points = 0;
	}
	else if (m_hit_points > 0)
		std::cout << m_name << " doesn't have enough energy points left." << std::endl;
	else
		std::cout << m_name << "is dead. " << std::endl;
}

void		ClapTrap::getStatus(void) {
	if (m_hit_points <= 0) {
		std::cout << m_name << " is dead. " << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << m_name << " has " << m_hit_points << " hit points left." << std::endl;
	std::cout << m_name << " has " << m_energy_points << " energy points left." << std::endl;
	std::cout << std::endl;
}

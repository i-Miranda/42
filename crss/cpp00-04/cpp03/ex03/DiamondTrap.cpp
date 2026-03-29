/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:08:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/29 22:42:15 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :	ClapTrap("Generic DiamondTrap_clap_name"),
									FragTrap(),
									ScavTrap(),
									m_name("Generic DiamondTrap") {
	m_hit_points = 100; // FragTrap::m_hit_points;
	m_energy_points = 50; // ScavTrap::m_energy_points;
	m_attack_damage = 30; // FragTrap::m_attack_damage;
	std::cout << m_name << "'s DiamondTrap Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) :	ClapTrap(name + "_clap_name"),
													FragTrap(name),
													ScavTrap(name),
													m_name(name) {
	m_hit_points = 100; // FragTrap::m_hit_points;
	m_energy_points = 50; // ScavTrap::m_energy_points;
	m_attack_damage = 30; // FragTrap::m_attack_damage;
	std::cout << m_name <<  "'s DiamondTrap Name constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) :	ClapTrap(src),
													FragTrap(src),
													ScavTrap(src),
													m_name(src.m_name) {
	std::cout << m_name << "'s DiamondTrap Copy constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << m_name << "'s DiamondTrap Destructor called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &src) {
	std::cout << m_name << "'s DiamondTrap Copy assignment constructor called." << std::endl;
	if (this != &src) {
		ClapTrap::operator=(src);
		m_name = src.m_name;
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << m_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::m_name  << std::endl;
}

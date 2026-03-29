/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/30 01:47:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	m_name = "Generic ScavTrap"; 
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_damage = 20;
	std::cout << m_name << "'s ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	m_hit_points = 100;
	m_energy_points = 50;
	m_attack_damage = 20;
	std::cout << m_name << "'s ScavTrap Name constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cout << m_name << "'s ScavTrap Copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void) { 
	std::cout << m_name << "'s ScavTrap Destructor called." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &src) {
	std::cout << m_name << "'s ScavTrap Copy assignment constructor called." << std::endl;
	if (this != &src) {
		ClapTrap::operator=(src);
		m_name = src.m_name;
	}
	return *this;
}

void		ScavTrap::attack(const std::string& target) {
	if (m_hit_points > 0 && m_energy_points >= 1) {
		m_energy_points--;
		std::cout << m_name << " attacks " << target << " with furious anger, causing " << m_attack_damage << " points of damage!" << std::endl;
		if (m_energy_points < 0)
			m_energy_points = 0;
	}
	else if (m_hit_points > 0)
		std::cout << m_name << " doesn't have enough energy points left." << std::endl;
	else
		std::cout << m_name << " is dead. " << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << m_name << " is now in Gate keeper mode." << std::endl;
}

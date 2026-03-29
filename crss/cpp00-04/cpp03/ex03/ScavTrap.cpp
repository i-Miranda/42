/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/29 21:43:48 by ivmirand         ###   ########.fr       */
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

void	ScavTrap::guardGate(void) {
	std::cout << m_name << " is now in Gate keeper mode." << std::endl;
}

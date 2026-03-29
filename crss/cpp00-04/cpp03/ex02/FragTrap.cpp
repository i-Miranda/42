/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/29 20:39:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	m_name = "Generic FragTrap"; 
	m_hit_points = 100;
	m_energy_points = 100;
	m_attack_damage = 30;
	std::cout << m_name << "'s FragTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	m_hit_points = 100;
	m_energy_points = 100;
	m_attack_damage = 30;
	std::cout << m_name << "'s FragTrap Name constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cout << "FragTrap Copy constructor called." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &src) {
	std::cout << m_name << "'s FragTrap Copy assignment constructor called." << std::endl;
	m_name = src.m_name;
	m_hit_points = src.m_hit_points;
	m_energy_points = src.m_energy_points;
	m_attack_damage = src.m_attack_damage;
	return *this;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << m_name << " high fives all of the guys!" << std::endl;
}

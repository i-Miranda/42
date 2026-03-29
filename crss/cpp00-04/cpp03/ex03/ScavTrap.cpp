/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 17:48:18 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):ClapTrap() {
	std::cerr << "ScavTrap Default constructor called." << std::endl;
	this->setName("Generic ScavTrap");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string name):ClapTrap(name) {
	std::cerr << "ScavTrap Name constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string name, const int hit_points):ClapTrap(name, hit_points) {
	std::cerr << "ScavTrap Hit points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string name, const int hit_points, const int energy_points) : ClapTrap(name, hit_points, energy_points) {
	std::cerr << "ScavTrap Energy points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage)  : ClapTrap(name, hit_points, energy_points) {
	std::cerr << "ScavTrap Attack damage constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(attack_damage);
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
	std::cerr << "ScavTrap Copy constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

ScavTrap::~ScavTrap(void) {
	std::cerr << "ScavTrap Destructor called." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &src) {
	std::cerr << "ScavTrap Copy assignment constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return *this;
}

void	ScavTrap::guardGate(void) {
	std::cerr << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}

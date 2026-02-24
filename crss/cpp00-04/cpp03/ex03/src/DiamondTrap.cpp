/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:08:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/19 16:56:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cerr << "DiamondTrap Default constructor called." << std::endl;
	this->setName("Generic DiamondTrap");
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	std::cerr << "DiamondTrap Name constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string name, const int hit_points) : ClapTrap(name + "_clap_name", hit_points), FragTrap(name, hit_points), ScavTrap(name, hit_points) {
	std::cerr << "DiamondTrap Hit points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string name, const int hit_points, const int energy_points) : ClapTrap(name + "_clap_name", hit_points, energy_points), FragTrap(name, hit_points, energy_points), ScavTrap(name, hit_points, energy_points) {
	std::cerr << "DiamondTrap Energy points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(FragTrap::getAttackDamage());
}
 
DiamondTrap::DiamondTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage) : ClapTrap(name + "_clap_name", hit_points, energy_points, attack_damage), FragTrap(name, hit_points, energy_points, attack_damage), ScavTrap(name, hit_points, energy_points, attack_damage) {
	std::cerr << "DiamondTrap Attack damage constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(attack_damage);
}
 
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src) {
	std::cerr << "DiamondTrap Copy constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

DiamondTrap::~DiamondTrap(void) {
	std::cerr << "DiamondTrap Destructor called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &src) {
	std::cerr << "DiamondTrap Copy assignment constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return *this;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << this->getName() << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}


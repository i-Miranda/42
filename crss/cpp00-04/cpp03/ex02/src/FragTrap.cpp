/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:26:54 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 19:29:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cerr << "FragTrap Default constructor called." << std::endl;
	this->setName("Generic FragTrap");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cerr << "FragTrap Name constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name, const int hit_points) : ClapTrap(name, hit_points) {
	std::cerr << "FragTrap Hit points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name, const int hit_points, const int energy_points) : ClapTrap(name, hit_points, energy_points) {
	std::cerr << "FragTrap Energy points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage) : ClapTrap(name, hit_points, energy_points) {
	std::cerr << "FragTrap Attack damage constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(attack_damage);
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
	std::cerr << "FragTrap Copy constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

FragTrap::~FragTrap(void) {
	std::cerr << "FragTrap Destructor called." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &src) {
	std::cerr << "FragTrap Copy assignment constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return *this;
}

void	FragTrap::highFiveGuys(void) {
	std::cerr << "FragTrap " << this->getName() << " high fives all of the guys!" << std::endl;
}

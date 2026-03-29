/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:07:49 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 13:35:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cerr << "Default constructor called." << std::endl;
	this->setName("Generic ClapTrap");
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
}

ClapTrap::ClapTrap(const std::string name) {
	std::cerr << "Name constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(10);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
}

ClapTrap::ClapTrap(const std::string name, const int hit_points) {
	std::cerr << "Hit points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(10);
	this->setAttackDamage(0);
}

ClapTrap::ClapTrap(const std::string name, const int hit_points, const int energy_points) {
	std::cerr << "Energy points constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(0);
}

ClapTrap::ClapTrap(const std::string name, const int hit_points, const int energy_points, const int attack_damage) {
	std::cerr << "Attack damage constructor called." << std::endl;
	this->setName(name);
	this->setHitPoints(hit_points);
	this->setEnergyPoints(energy_points);
	this->setAttackDamage(attack_damage);
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cerr << "Copy constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
}

ClapTrap::~ClapTrap(void) {
	std::cerr << "Destructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src) {
	std::cerr << "Copy assignment constructor called." << std::endl;
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	return *this;
}

void		ClapTrap::setName(const std::string& name) {
	this->m_name = name;
}

std::string	ClapTrap::getName(void) const {
	return this->m_name;
}

void		ClapTrap::setHitPoints(const int hit_points) {
	this->m_hit_points = hit_points;
}

int			ClapTrap::getHitPoints(void) const {
	return this->m_hit_points;
}

void		ClapTrap::setEnergyPoints(const int energy_points) {
	this->m_energy_points = energy_points;
}

int			ClapTrap::getEnergyPoints(void) const {
	return this->m_energy_points;
}

void		ClapTrap::setAttackDamage(const int attack_damage) {
	this->m_attack_damage = attack_damage;
}

int			ClapTrap::getAttackDamage(void) const {
	return this->m_attack_damage;
}

void		ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int	amount) {
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int	amount) {
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << "ClapTrap " << this->getName() << " repairs " << amount << " points of damage!" << std::endl;
}

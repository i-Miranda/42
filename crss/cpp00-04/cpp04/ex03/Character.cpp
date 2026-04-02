/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:00:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 16:22:47 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "FloorManager.hpp"

static FloorManager g_floor;

Character::Character(std::string const _name) : m_name(_name) {
	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}
}

Character::Character(const Character& src) : m_name(src.getName()) {
	for (int i = 0; i < 4; i++) {
		m_inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++) {
		if (src.m_inventory[i] != NULL)
			m_inventory[i] = src.m_inventory[i]->clone();
	}
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		delete m_inventory[i];
		m_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& src) {
	if (this != &src) {
		m_name = src.getName();
		for (int i = 0; i < 4; i++) {
			delete m_inventory[i];
			m_inventory[i] = NULL;
			if (src.m_inventory[i] != NULL)
				m_inventory[i] = src.m_inventory[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return m_name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "Materia is null." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (m_inventory[i] == NULL) {
			m_inventory[i] = m;
			std::cout << "Materia equipped." << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
	delete m; // If we are here we need to prevent the leak.
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << "Inventory slot is empty." << std::endl;
		return ;
	}
	g_floor.store(m_inventory[idx]);
	m_inventory[idx] = NULL;
	std::cout << "Materia unequipped. (Dropped on floor)" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (m_inventory[idx] == NULL) {
		std::cout << "Inventory slot is empty." << std::endl;
		return ;
	}
	m_inventory[idx]->use(target); 
}

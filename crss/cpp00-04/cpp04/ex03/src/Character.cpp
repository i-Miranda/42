/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:00:31 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 23:03:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "FloorManager.hpp"

Character::Character(std::string const _name) {
	this->m_name = _name;
	for (int i = 0; i < 4; i++) {
		this->m_inventory[i] = NULL;
	}
}

Character::Character(const Character& src) {
	if (this != &src) {
		this->m_name = src.getName();
		for (int i = 0; i < 4; i++) {
			if (this->m_inventory[i] != NULL)
				delete m_inventory[i];
			this->m_inventory[i] = src.m_inventory[i]->clone();
		}
	}
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (this->m_inventory[i] != NULL)
			delete m_inventory[i];
	}
}

std::string const & Character::getName() const {
	return this->m_name;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "Materia is null." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->m_inventory[i] == NULL) {
			this->m_inventory[i] = m;
			std::cout << "Materia equipped." << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
}

void Character::unequip(int idx) {
	if (this->m_inventory[idx] == NULL) {
		std::cout << "Inventory slot is empty." << std::endl;
		return ;
	}
	UpdateFloor(this->m_inventory[idx]);
	std::cout << "Materia unequipped." << std::endl;
	this->m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (this->m_inventory[idx] == NULL) {
		std::cout << "Inventory slot is empty." << std::endl;
		return ;
	}
	this->m_inventory[idx]->use(target); 
}

Character& Character::operator=(const Character& src) {
	if (this != &src) {
		this->m_name = src.getName();
		for (int i = 0; i < 4; i++) {
			if (this->m_inventory[i] != NULL)
				delete m_inventory[i];
			this->m_inventory[i] = src.m_inventory[i]->clone();
		}
	}
	return *this;
}

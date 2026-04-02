/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloorManager.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:46:35 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 16:06:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloorManager.hpp"

FloorManager::FloorManager() {
	for (int i = 0; i < 100; ++i)
		m_floor[i] = NULL;
}

FloorManager::FloorManager(const FloorManager& src) {
	for (int i = 0; i < 100; ++i)
		m_floor[i] = NULL;
	*this = src;
}

FloorManager::~FloorManager() {
	for (int i = 0; i < 100; ++i) {
		delete m_floor[i];
		m_floor[i] = NULL;
	}
}

FloorManager& FloorManager::operator=(const FloorManager& src) {
	if (this != &src) {
		for (int i = 0; i < 100; ++i) {
			delete m_floor[i];
			if (src.m_floor[i] != NULL)
				m_floor[i] = src.m_floor[i]->clone();
			else
				m_floor[i] = NULL;
		}
	}
	return *this;
}

void FloorManager::store(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 100; i++) {
		if (m_floor[i] == NULL) {
			m_floor[i] = m;
			return ;
		}
	}
	std::cout << "Floor is full. Deleting first Materia in floor." << std::endl;
	delete m_floor[0];
	for (int i = 1; i < 100; ++i) {
		m_floor[i - 1] = m_floor[i];
	}
	m_floor[99] = m;
}

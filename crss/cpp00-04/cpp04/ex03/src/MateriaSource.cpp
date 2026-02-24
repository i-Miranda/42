/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:28:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 23:07:17 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->m_known_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (src.m_known_materia[i] != NULL)
				this->m_known_materia[i] = src.m_known_materia[i]->clone();
			else
				this->m_known_materia[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		delete m_known_materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL) {
		std::cout << "Materia is null." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->m_known_materia[i] == NULL) {
			this->m_known_materia[i] = m;
			std::cout << "Materia learned." << std::endl;
			return ;
		}
	}
	std::cout << "Known_Materia is full." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if (type.empty()) {
		std::cerr << "Invalid type." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < 4; i++) {
		if (this->m_known_materia[i] != NULL
				&& this->m_known_materia[i]->getType() == type) {
			std::cout << "Materia learned." << std::endl;
			return this->m_known_materia[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not known." << std::endl;
	return (NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (this->m_known_materia[i] != NULL)
				delete m_known_materia[i];
			this->m_known_materia[i] = src.m_known_materia[i]->clone();
		}
	}
	return *this;
}

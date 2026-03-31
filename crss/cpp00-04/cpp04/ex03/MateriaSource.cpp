/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:28:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 18:19:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource Default Constructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		m_known_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	std::cout << "MateriaSource Copy Constructor called." << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (src.m_known_materia[i] != NULL)
				m_known_materia[i] = src.m_known_materia[i]->clone();
			else
				m_known_materia[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource Destructor called." << std::endl;
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
		if (m_known_materia[i] == NULL) {
			m_known_materia[i] = m;
			std::cout << "Materia learned." << std::endl;
			return ;
		}
	}
	std::cout << "Known_Materia is full." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if (type.empty()) {
		std::cout << "Invalid type." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < 4; i++) {
		if (m_known_materia[i] != NULL
				&& m_known_materia[i]->getType() == type) {
			std::cout << "Materia learned." << std::endl;
			return m_known_materia[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not known." << std::endl;
	return (NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	std::cout << "MateriaSource Copy Assignment operator called." << std::endl;
	if (this != &src) {
		for (int i = 0; i < 4; i++) {
			if (m_known_materia[i] != NULL)
				delete m_known_materia[i];
			m_known_materia[i] = src.m_known_materia[i]->clone();
		}
	}
	return *this;
}

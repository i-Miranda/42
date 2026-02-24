/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:28:18 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 18:41:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		this->m_known_materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	if (this != src) {
		for (int i = 0; i < 4; i++) {
			if (this->m_known_materia[i] != NULL)
				delete m_known_materia[i];
			this->m_known_materia[i] = new AMateria(src.m_known_materia[i]);
		}
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (this->m_known_materia[i] != NULL)
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
	AMateria* clone;
	if (type == NULL || type.length() <= 0) {
		std::cerr << "Invalid type." << std::endl;
		return (0);
	}
	for (int i = 0; i < 4; i++) {
		if (this->m_known_materia[i].getType() == type) {
			clone = this->m_known_materia[i].clone();
			std::cout << "Materia learned." << std::endl;
			return ;
		}
	}
	std::cout << "Materia of type " << type << " not known." << std::endl;
	return (0);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	if (this != src) {
		this->m_name = src.getName();
		for (int i = 0; i < 4; i++) {
			if (this->m_known_materia[i] != NULL)
				delete m_known_materia[i];
			this->m_known_materia[i] = new AMateria(src.m_known_materia[i]);
		}
	}
	return *this;
}

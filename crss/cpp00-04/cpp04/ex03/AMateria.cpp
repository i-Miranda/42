/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:34:05 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 18:21:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & materia_type) : type(materia_type) {
	std::cout << "AMateria Default Constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& src) : type(src.getType()) {
	std::cout << "AMateria Copy Constructor called." << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src) {
	std::cout << "AMateria Copy Assignment operator called." << std::endl;
	if (this != &src) {
		type = src.getType();
	}
	return *this;
}

std::string const & AMateria::getType(void) const {
	return type;
}

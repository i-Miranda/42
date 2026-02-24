/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:34:05 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 11:10:04 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	std::cout << "AMateria Default Constructor called." << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& src) {
	std::cout << "AMateria Copy Constructor called." << std::endl;
	this->type = src.type;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src) {
	std::cout << "AMateria Copy Assignment Constructor called." << std::endl;
	if (this != &src)
	{
		delete this;
		this = new AMateria(src);
	}
	return *this;
}

std::string const & AMateria::getType(void) const {
	return this->type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:34:05 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 18:05:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure Default Constructor called." << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src) {
	std::cout << "Cure Copy Constructor called." << std::endl;
}

Cure::~Cure(void) {
	std::cout << "Cure Destructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& src) {
	std::cout << "Cure Copy Assignment operator called." << std::endl;
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

AMateria* Cure::clone(void) const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

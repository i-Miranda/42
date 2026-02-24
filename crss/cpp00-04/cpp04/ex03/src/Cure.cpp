/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:34:05 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 11:09:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(std::string const & type) {
	std::cout << "Cure Default Constructor called." << std::endl;
	this->type = type;
}

Cure::Cure(const Cure& src) {
	std::cout << "Cure Copy Constructor called." << std::endl;
	this->type = src.type;
}

Cure::~Cure(void) {
	std::cout << "Cure Destructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& src) Assignment {
	std::cout << "Cure Copy Assignment Constructor called." << std::endl;
	if (this != &src)
	{
		delete this;
		this = new Cure(src);
	}
	return *this;
}

AMateria* Cure::clone(void) const {
	AMateria* cure;	
	cure = new Cure(this); 
	return cure;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target->name << "'s wounds *" << std::endl;
	delete this;
}

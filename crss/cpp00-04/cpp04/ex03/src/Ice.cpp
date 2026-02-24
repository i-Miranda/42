/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:34:05 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/24 22:54:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice Default Constructor called." << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src) {
	std::cout << "Ice Copy Constructor called." << std::endl;
}

Ice::~Ice(void) {
	std::cout << "Ice Destructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& src) {
	std::cout << "Ice Copy Assignment Constructor called." << std::endl;
	if (this != &src) {
		AMateria::operator=(src);
	}
	return *this;
}

AMateria* Ice::clone(void) const { return new Ice(*this); }

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

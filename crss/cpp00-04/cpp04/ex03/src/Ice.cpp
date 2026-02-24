/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:34:05 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 11:10:04 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(std::string const & type) {
	std::cout << "Ice Default Constructor called." << std::endl;
	this->type = type;
}

Ice::Ice(const Ice& src) {
	std::cout << "Ice Copy Constructor called." << std::endl;
	this->type = src.type;
}

Ice::~Ice(void) {
	std::cout << "Ice Destructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& src) Assignment {
	std::cout << "Ice Copy Assignment Constructor called." << std::endl;
	if (this != &src)
	{
		delete this;
		this = new Ice(src);
	}
	return *this;
}

AMateria* Ice::clone(void) const {
	AMateria* ice;
	ice = new Ice(this);
	return ice;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target->name << " *" << std::endl;
	delete this;
}

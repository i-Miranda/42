/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 17:48:50 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal") {
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& src) : type(src.getType()) {
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src) {
	std::cout << "AAnimal copy assignment constructor called." << std::endl;
	if (this != &src)
		type = src.getType();
	return *this;
}

std::string AAnimal::getType(void) const {
	return type;
}

void		AAnimal::setType(const std::string animal_type) {
	type = animal_type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 02:03:14 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal default constructor called." << std::endl;
	this->setType("AAnimal");
}

AAnimal::AAnimal(const AAnimal& src) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	this->setType(src.getType());
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src) {
	std::cout << "AAnimal copy assignment constructor called." << std::endl;
	this->setType(src.getType());
	return *this;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

void		AAnimal::setType(const std::string type) {
	this->type = type;
}

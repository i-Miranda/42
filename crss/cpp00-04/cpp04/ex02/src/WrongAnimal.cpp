/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/20 13:09:46 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called." << std::endl;
	this->setType("WrongAnimal");
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	this->setType(src.getType());
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	std::cout << "WrongAnimal copy assignment constructor called." << std::endl;
	this->setType(src.getType());
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "\"WrongAnimal sound.\"" << std::endl;
}


std::string WrongAnimal::getType(void) const {
	return this->type;
}

void		WrongAnimal::setType(const std::string type) {
	this->type = type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/20 12:48:37 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called." << std::endl;
	this->setType("Animal");
}

Animal::Animal(const Animal& src) {
	std::cout << "Animal copy constructor called." << std::endl;
	this->setType(src.getType());
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called." << std::endl;
}


Animal& Animal::operator=(const Animal& src) {
	std::cout << "Animal copy assignment constructor called." << std::endl;
	this->setType(src.getType());
	return *this;
}


void	Animal::makeSound(void) const {
	std::cout << "\"Animal sound.\"" << std::endl;
}


std::string Animal::getType(void) const {
	return this->type;
}

void		Animal::setType(const std::string type) {
	this->type = type;
}

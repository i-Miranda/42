/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 13:27:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal& src) : type(src.getType()) {
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &src)
		type = src.getType();
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "\"Animal sound.\"" << std::endl;
}

std::string Animal::getType(void) const {
	return type;
}

void		Animal::setType(const std::string animal_type) {
	type = animal_type;
}

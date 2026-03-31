/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 15:40:19 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src) {
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &src)
		type = src.getType();
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "\"Woof.\"" << std::endl;
}

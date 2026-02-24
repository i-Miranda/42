/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/20 12:58:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->setType(src.getType());
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment constructor called." << std::endl;
	this->setType(src.getType());
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meowwww." << std::endl;
}

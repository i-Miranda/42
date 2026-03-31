/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 15:39:07 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &src)
		type = src.getType();
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "\"Meowwww.\"" << std::endl;
}

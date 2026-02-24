/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 00:16:52 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	this->setType("Cat");
	this->m_brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->setType(src.getType());
	this->m_brain = new Brain(src.getBrain());
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." << std::endl;
	delete this->m_brain;
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment constructor called." << std::endl;
	if (this != &src) {
		Animal::operator=(src);
		delete this->m_brain;
		this->m_brain = new Brain(src.getBrain());
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meowwww." << std::endl;
}

Brain&	Cat::getBrain(void) {
	return *this->m_brain;
}
const Brain&	Cat::getBrain(void) const {
	return *this->m_brain;
}

void	Cat::setBrain(const Brain& src) {
	*this->m_brain = src;
}

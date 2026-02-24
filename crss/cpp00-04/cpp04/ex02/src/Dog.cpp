/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 02:12:11 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal() {
	std::cout << "Dog default constructor called." << std::endl;
	this->setType("Dog");
	this->m_brain = new Brain();
}

Dog::Dog(const Dog& src) : AAnimal(src) {
	std::cout << "Dog copy constructor called." << std::endl;
	this->setType(src.getType());
	this->m_brain = new Brain(src.getBrain());
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called." << std::endl;
	delete this->m_brain;
}

Dog& Dog::operator=(const Dog& src) {
	std::cout << "Dog copy assignment constructor called." << std::endl;
	if (this != &src) {
		AAnimal::operator=(src);
		delete this->m_brain;
		this->m_brain = new Brain(src.getBrain());
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof." << std::endl;
}

Brain& Dog::getBrain(void) {
	return *this->m_brain;
}

const Brain& Dog::getBrain(void) const {
	return *this->m_brain;
}

void	Dog::setBrain(const Brain& src) {
	*this->m_brain = src;
}

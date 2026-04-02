/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 13:09:37 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal() {
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
	m_brain = new Brain();
}

Dog::Dog(const Dog& src) : AAnimal(src) {
	std::cout << "Dog copy constructor called." << std::endl;
	m_brain = new Brain(src.getBrain());
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called." << std::endl;
	delete m_brain;
}

Dog& Dog::operator=(const Dog& src) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &src) {
		Brain* newBrain = new Brain(src.getBrain());
		AAnimal::operator=(src);
		delete m_brain;
		m_brain = newBrain;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "\"Woof.\"" << std::endl;
}

Brain& Dog::getBrain(void) {
	return *m_brain;
}

const Brain& Dog::getBrain(void) const {
	return *m_brain;
}

void	Dog::setBrain(const Brain& src) {
	*m_brain = src;
}

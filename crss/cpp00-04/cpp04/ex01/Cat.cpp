/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/31 16:38:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	std::cout << "Cat default constructor called." << std::endl;
	type = "Cat";
	m_brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src) {
	std::cout << "Cat copy constructor called." << std::endl;
	m_brain = new Brain(src.getBrain());
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called." << std::endl;
	delete m_brain;
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &src) {
		Brain* newBrain = new Brain(src.getBrain());
		Animal::operator=(src);
		delete m_brain;
		m_brain = newBrain;
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "\"Meowwww.\"" << std::endl;
}

Brain&	Cat::getBrain(void) {
	return *m_brain;
}
const Brain&	Cat::getBrain(void) const {
	return *m_brain;
}

void	Cat::setBrain(const Brain& src) {
	*m_brain = src;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:16:39 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/23 01:32:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->setIdea(src.getIdea(i), i);
	}
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& src) {
	std::cout << "Brain copy assignment constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->setIdea(src.getIdea(i), i);
	}
	return *this;
}

const std::string& Brain::getIdea(const int index) const {
	return this->m_ideas[index];
}

void		Brain::setIdea(const std::string idea, const int index) {
	this->m_ideas[index] = idea;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:16:39 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 13:03:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		setIdea(src.getIdea(i), i);
	}
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& src) {
	std::cout << "Brain copy assignment constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		setIdea(src.getIdea(i), i);
	}
	return *this;
}

const std::string& Brain::getIdea(const int index) const {
	static const std::string outOfBounds = "Error: Index out of range (0-99 only).";
	static const std::string emptyIdea = "Warning: No idea here yet.";
	if (index < 0 || index >= 100)
		return outOfBounds;
	if (m_ideas[index].empty())
		return emptyIdea;
	return m_ideas[index];
}


void		Brain::setIdea(const std::string& idea, const int index) {
	if (index < 0 || index >= 100) {
		std::cout << "Cannot set idea at index " << index << ". Out of bounds." << std::endl;
		return ;
	}
	m_ideas[index] = idea;
}

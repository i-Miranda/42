/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:24 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/20 13:20:01 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor called." << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	this->setType(src.getType());
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
	std::cout << "WrongCat copy assignment constructor called." << std::endl;
	this->setType(src.getType());
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meowwww." << std::endl;
}

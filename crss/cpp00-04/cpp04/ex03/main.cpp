/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/04/02 14:58:22 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int	main(void) {
	std::cout << "--------SUBJECT TEST--------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	std::cout << std::endl;
	std::cout << "--------UNKNOWN MATERIA TEST--------" << std::endl;
	tmp = src->createMateria("fire");
	if (!tmp)
		std::cout << "fire not created: OK" << std::endl;
	else
		delete tmp;
	
	std::cout << std::endl;
	std::cout << "--------INVALID INDEX TEST--------" << std::endl;
	me->use(-1, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}

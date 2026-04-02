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
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== SUBJECT TEST ===\n";
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

    std::cout << "\n=== UNKNOWN MATERIA TEST ===\n";
    tmp = src->createMateria("fire");
    if (!tmp)
        std::cout << "fire not created: OK\n";
    else
        delete tmp;

    std::cout << "\n=== INVALID INDEX TEST ===\n";
    me->use(-1, *bob);
    me->use(4, *bob);

    std::cout << "\n=== INVENTORY FULL TEST ===\n";
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice")); // should be full here

    std::cout << "\n=== UNEQUIP TEST ===\n";
    me->unequip(0);
    me->use(0, *bob); // should not work
    me->equip(src->createMateria("ice"));
    me->use(0, *bob);

    std::cout << "\n=== CHARACTER DEEP COPY TEST ===\n";
    Character* alice = new Character("alice");
    alice->equip(src->createMateria("ice"));
    alice->equip(src->createMateria("cure"));

    Character* copyAlice = new Character(*alice);
    std::cout << "Original uses:\n";
    alice->use(0, *bob);
    alice->use(1, *bob);

    std::cout << "Copy uses:\n";
    copyAlice->use(0, *bob);
    copyAlice->use(1, *bob);

    std::cout << "Unequip original slot 0\n";
    alice->unequip(0);

    std::cout << "Original after unequip:\n";
    alice->use(0, *bob);      // should fail / do nothing
    std::cout << "Copy after original unequip:\n";
    copyAlice->use(0, *bob);  // must still work if deep copy is correct

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n";
    Character basic("basic");
    basic = *copyAlice;
    basic.use(0, *bob);
    basic.use(1, *bob);

    copyAlice->unequip(1);
    std::cout << "Assigned copy after source unequip:\n";
    basic.use(1, *bob); // must still work if operator= deep copies correctly

    std::cout << "\n=== MATERIASOURCE DEEP COPY TEST ===\n";
    MateriaSource* ms1 = new MateriaSource();
    ms1->learnMateria(new Ice());
    ms1->learnMateria(new Cure());

    MateriaSource* ms2 = new MateriaSource(*ms1);
    AMateria* a = ms2->createMateria("ice");
    AMateria* b = ms2->createMateria("cure");

    if (a)
    {
        std::cout << "Copied source created ice: OK\n";
        delete a;
    }
    if (b)
    {
        std::cout << "Copied source created cure: OK\n";
        delete b;
    }

    delete ms1;

    a = ms2->createMateria("ice");
    if (a)
    {
        std::cout << "Copied source still works after original deleted: OK\n";
        delete a;
    }

    delete ms2;

    delete copyAlice;
    delete alice;
    delete bob;
    delete me;
    delete src;

    return 0;
}

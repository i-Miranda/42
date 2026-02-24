/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 18:03:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap a = ClapTrap("ClapTrap_A");	
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	std::cout << a.getName() << " has " << a.getEnergyPoints() << " energy points." << std::endl;
	std::cout << a.getName() << " has " << a.getAttackDamage() << " attack damage." << std::endl;

	std::cout << std::endl;
	ScavTrap b = ScavTrap("ScavTrap_B");
	std::cout << b.getName() << " has " << b.getHitPoints() << " hit points." << std::endl;
	std::cout << b.getName() << " has " << b.getEnergyPoints() << " energy points." << std::endl;
	std::cout << b.getName() << " has " << b.getAttackDamage() << " attack damage." << std::endl;

	std::cout << std::endl;
	FragTrap c = FragTrap("FragTrap_C");
	std::cout << c.getName() << " has " << c.getHitPoints() << " hit points." << std::endl;
	std::cout << c.getName() << " has " << c.getEnergyPoints() << " energy points." << std::endl;
	std::cout << c.getName() << " has " << c.getAttackDamage() << " attack damage." << std::endl;


	std::cout << std::endl;
	a.attack("Target");
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	a.takeDamage(1);
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	a.beRepaired(1);
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	
	std::cout << std::endl;
	b.attack("Target");
	std::cout << b.getName() << " has " << b.getHitPoints() << " hit points." << std::endl;
	b.takeDamage(1);
	std::cout << b.getName() << " has " << b.getHitPoints() << " hit points." << std::endl;
	b.beRepaired(1);
	std::cout << b.getName() << " has " << b.getHitPoints() << " hit points." << std::endl;
	
	std::cout << std::endl;
	c.attack("Target");
	std::cout << c.getName() << " has " << c.getHitPoints() << " hit points." << std::endl;
	c.takeDamage(1);
	std::cout << c.getName() << " has " << c.getHitPoints() << " hit points." << std::endl;
	c.beRepaired(1);
	std::cout << c.getName() << " has " << c.getHitPoints() << " hit points." << std::endl;
	
	std::cout << std::endl;
	b.guardGate();

	std::cout << std::endl;
	c.highFiveGuys();

	std::cout << std::endl;
	std::cout << "Traps Heap Test" << std::endl;
	ClapTrap *clap_test = new ClapTrap("ClapTrap_Heap");
	ScavTrap *scav_test = new ScavTrap("ScavTrap_Heap");
	FragTrap *frag_test = new FragTrap("FragTrap_Heap");
	delete clap_test;
	delete scav_test;
	delete frag_test;

	std::cout << std::endl;
	return (0);
}

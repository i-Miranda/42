/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/30 00:30:32 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap a = ClapTrap("ClapTrap_A");	
	a.getStatus();
	std::cout << std::endl;

	ScavTrap b = ScavTrap("ScavTrap_B");
	b.getStatus();
	std::cout << std::endl;

	FragTrap c = FragTrap("FragTrap_C");
	c.getStatus();
	std::cout << std::endl;

	a.attack("Target");
	a.getStatus();
	a.takeDamage(1);
	a.getStatus();
	a.beRepaired(1);
	a.getStatus();
	std::cout << std::endl;

	b.attack("Target");
	b.getStatus();
	b.takeDamage(1);
	b.getStatus();
	b.beRepaired(1);
	b.getStatus();
	std::cout << std::endl;
	
	c.attack("Target");
	c.getStatus();
	c.takeDamage(1);
	c.getStatus();
	c.beRepaired(1);
	c.getStatus();
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	c.highFivesGuys();
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

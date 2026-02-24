/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 17:49:39 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
	b.guardGate();

	std::cout << std::endl;
	return (0);
}

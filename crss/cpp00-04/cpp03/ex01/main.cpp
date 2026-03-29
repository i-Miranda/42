/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/29 15:15:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap a = ClapTrap("ClapTrap_A");	
	a.getStatus();
	std::cout << std::endl;

	ScavTrap b = ScavTrap("ScavTrap_B");
	b.getStatus();
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

	b.guardGate();
	std::cout << std::endl;

	return (0);
}

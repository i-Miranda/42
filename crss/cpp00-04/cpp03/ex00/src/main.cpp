/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 04:38:56 by ivmirand          #+#    #+#             */
/*   Updated: 2026/02/18 13:35:20 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap a = ClapTrap("ClapTrap_A");	

	a.attack("Target");
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	a.takeDamage(1);
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	a.beRepaired(1);
	std::cout << a.getName() << " has " << a.getHitPoints() << " hit points." << std::endl;
	
	return (0);
}

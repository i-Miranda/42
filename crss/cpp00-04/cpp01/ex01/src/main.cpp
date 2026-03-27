/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:21:34 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/24 15:21:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Zombie.hpp"

int	main(int argc, char *argv[]) {
	int	n;

	if (argc <= 1) {
		std::cerr << "Args count must be 1 or 2. Usage: ./ex00 (int zombie count) (string zombie name)" << std::endl;
		return (1);
	}

	n = std::atoi(argv[1]); 
	if (n == 0)
		return (1);

	Zombie *horde;

	if (argc == 2)
		horde = zombieHorde(n, "Zombie");	
	else
		horde = zombieHorde(n, argv[2]);	
	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}
	std::cout << std::endl;
	
	delete[] horde;
	return (0);
}

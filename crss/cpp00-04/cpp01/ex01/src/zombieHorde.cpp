/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:21:43 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/24 15:21:45 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde;

	horde = new Zombie[N];
	std::cout << std::endl;

	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
		std::cout << "Stack allocated " << name << " zombie copied into horde[" << i << "]." << std::endl;
	}
	return (horde); 
}

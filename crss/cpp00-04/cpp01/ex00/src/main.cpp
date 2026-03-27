/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:25:06 by ivmirand          #+#    #+#             */
/*   Updated: 2026/03/27 20:22:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie = Zombie("Stack_Zombie");		
	Zombie	*new_zombie = newZombie("Heap_Zombie");	

	randomChump("Random_Chump");
	Zombie randomChump = randomChump("Random_Chump");

	zombie.announce();
	new_zombie->announce();
	

	delete new_zombie;
	delete randomChump;
	return (0);
}

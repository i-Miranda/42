#include "Zombie.hpp"

int	main(void) {
	Zombie	zombie = Zombie("Stack_Zombie");		
	Zombie	*new_zombie = newZombie("Heap_Zombie");	

	zombie.announce();
	randomChump("Random_Chump");
	new_zombie->announce();
	
	delete new_zombie;
	return (0);
}

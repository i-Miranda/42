#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde;

	for (int i = 0; i < N; i++) {
		horde[i] = new Zombie(name);		
	}
	return (horde); 
}
